#include <stdlib.h>
typedef int T_list;

typedef struct node {
    T_list val; struct node *prv, *nxt;
} node;

typedef struct list {
    node *front, *back;
} list;

list newlist() {
    list res = {NULL, NULL};
    return res;
}

node* newnode(T_list x) {
    node *nd = malloc(sizeof *nd);
    nd->val = x; nd->prv = nd->nxt = NULL;
    return nd;
}

void push_front(list *ls, T_list x) {
    node *nd = newnode(x);
    if(ls->front == NULL) ls->back = nd;
    else ls->front->prv = nd;
    nd->nxt = ls->front; ls->front = nd;
}

void push_back(list *ls, T_list x) {
    node *nd = newnode(x);
    if(ls->back == NULL) ls->front = nd;
    else ls->back->nxt = nd;
    nd->prv = ls->back; ls->back = nd;
}

node* pop_front(list *ls) {
#ifdef assert
    assert(ls->front != NULL && "pop empty list");
#endif
    node *ret = ls->front;
    if(ret->nxt == NULL) ls->back = NULL;
    else ret->nxt->prv = NULL;
    ls->front = ret->nxt;
    return ret;
}

node* pop_back(list *ls) {
#ifdef assert
    assert(ls->back != NULL && "pop empty list");
#endif
    node *ret = ls->back;
    if(ret->prv == NULL) ls->front = NULL;
    else ret->prv->nxt = NULL;
    ls->back = ret->prv;
    return ret;
}
