int *g[N], deg[N];

void add(int u, int v) {
    int o = deg[u]++;
    if(o >= 2 && !(o & o-1))
        g[u] = realloc(g[u], o * 2 * sizeof *g[u]);
    g[u][o] = v;
}

for(i = 0; i < n; i++)
    g[i] = malloc(2 * sizeof *g[i]);