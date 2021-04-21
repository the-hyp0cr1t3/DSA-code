typedef struct {
    int key, pos;
} item;

typedef struct {
    int size, capacity; item **_pq;
    int (*cmp)(item*, item*);
} priority_queue;

#define newpq(_cmp) { .size = 0, .capacity = 2, ._pq = malloc(2 * sizeof(item*)), .cmp = _cmp }

int __nxt(priority_queue *pq, int x) {
    return (x <<= 1) > pq->size ? 0 : x | (x < pq->size && pq->cmp(pq->_pq[x|1], pq->_pq[x]));
}

item* pop(priority_queue *pq) {
    item *v = pq->_pq[1], *u = pq->_pq[pq->size--];
    if(v != u) {
        int x, p; item *o; u->pos = 1;
        for(x = u->pos; (p = __nxt(pq, x)) && pq->cmp(o = pq->_pq[p], u); x = p)
            pq->_pq[o->pos = x] = o;
        pq->_pq[u->pos = x] = u;
    } return v->pos = 0, v;
}

void up(priority_queue *pq, item *v) {
    int x, p; item *o;
    for(x = v->pos; (p = x >> 1) && pq->cmp(v, o = pq->_pq[p]); x = p)
        pq->_pq[o->pos = x] = o;
    pq->_pq[v->pos = x] = v;
}

void push(priority_queue *pq, item *v) {
    int cap = pq->capacity;
    if(cap == ++pq->size && cap >= 2 && !(cap & cap-1)) {
        pq->capacity <<= 1;
        pq->_pq = realloc(pq->_pq, cap * 2 * sizeof *pq->_pq);
    } up(pq, pq->_pq[v->pos = pq->size] = v);
}

int less(item *x, item *y) { return x->key < y->key; }
int greater(item *x, item *y) { return x->key > y->key; }