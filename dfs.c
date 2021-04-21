void dfs(int v, int p) {
    for(int o = deg[v]; o--; ) {
        int x = g[v][o];
        if(x == p) continue;
        dfs(x, v);
    }
}