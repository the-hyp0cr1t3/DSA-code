int pqcmp(int v, int o) { return a[v] < a[o]; }
 
int pq[N], pos[N], pq_cnt;
int __nxt(int x) {
    return (x <<= 1) > pq_cnt ? 0 : x | (x < pq_cnt && pqcmp(pq[x|1], pq[x]));
}
 
int pop() {
    int v = pq[1], u = pq[pq_cnt--];
    if(v ^ u) {
        int x, p, o; pos[u] = 1;
        for(x = pos[u]; (p = __nxt(x)) && pqcmp(o = pq[p], u); x = p)
            pq[pos[o] = x] = o;
        pq[pos[u] = x] = u;
    } return pos[v] = 0, v;
}

void up(int v) {
    int x, p, o;
    for(x = pos[v]; (p = x >> 1) && pqcmp(v, o = pq[p]); x = p)
        pq[pos[o] = x] = o;
    pq[pos[v] = x] = v;
}

void push(int v) {
    up(pq[pos[v] = ++pq_cnt] = v);
}