typedef int T;
int pqcmp(T x, T y) {
    return x > y;
}

int __nxt(T *A, int n, int x) {
    return (x <<= 1) > n ? 0 : x | (x < n && pqcmp(A[x|1], A[x]));
}

void heapify(T *A, int n, int x) {
    T u = A[x];
    for(int p; (p = __nxt(A, n, x)) && pqcmp(A[p], u); x = p)
        A[x] = A[p];
    A[x] = u;
}

void sort(T *A, int n) {
    for(int i = n/2; i--;)
        heapify(A, n, i+1);
    for(int i = n; --i; ) {
        A[1] ^= A[i+1] ^= A[1] ^= A[i+1];
        heapify(A, i, 1);
    }
}