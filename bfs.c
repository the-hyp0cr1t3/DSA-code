int d[N];

void bfs(int root) {
    memset(d, -1, n * sizeof *d);
    int q[N], front = 0, back = 0;
    q[back++] = root; d[root] = 0;
    while(front < back) {
        int v = q[front++];
        for(int o = deg[v]; o--; ) {
            int x = g[v][o];
            if(d[x] == -1) {
                d[x] = d[v] + 1;
                q[back++] = x;
            }
        }
    }
}