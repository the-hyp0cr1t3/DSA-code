int par[N], rootcnt, roots[N], rootID[N];

int get_par(int u) {
    return par[u] < 0? u : (par[u] = get_par(par[u]));
}

int merge(int u, int v) {
    u = get_par(u); v = get_par(v);
    if(u == v) return 0;
    if(-par[u] < -par[v]) u ^= v ^= u ^= v;
    par[u] += par[v]; par[v] = u;
    return 1;
}

void get_roots(int n) {
    for(int i = 0; i < n; i++) {
        if(par[i] < 0) {
            roots[rootcnt] = i;
            rootID[i] = rootcnt++;
        }
    }
}

memset(par, -1, (n+1) * sizeof *par);
memset(roots, -1, (n+1) * sizeof *roots);
memset(rootID, -1, (n+1) * sizeof *rootID);