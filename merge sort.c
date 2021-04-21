typedef int T;

void merge(T *beg, T *mid, T *end, int (*compare)(T*, T*)) {
    static T buff[N];
    T *m = mid, *b = beg; int top = 0;
    while(b < mid && m < end)
        buff[top++] = (*compare)(b, m)? *b++ : *m++;
    while(b < mid) buff[top++] = *b++;
    while(m < end) buff[top++] = *m++;
    for(top = 0; beg < end; *beg++ = buff[top++]);
}

void sort(T *beg, T *end, int (*compare)(T*, T*)) {
    if(end - beg <= 1) return;
    T *mid = beg + (end - beg)/2;
    sort(beg, mid, compare); sort(mid, end, compare);
    merge(beg, mid, end, compare);
}

int less(T *A, T *B) { return *A < *B; }