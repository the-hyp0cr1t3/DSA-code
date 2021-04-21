typedef int T;

void swap(T *x, T *y) {
    T z = *x; *x = *y; *y = z;
}

T* partition(T *beg, T *end, int (*compare)(T*, T*)) {
    T *have = beg, *cur = beg; --end;
    for(; cur != end; cur++)
        if((*compare)(cur, end))
            swap(cur, have++);
    swap(end, have);
    return have;
}

void sort(T *beg, T *end, int (*compare)(T*, T*)) {
    if(end - beg <= 1) return;
    T *p = partition(beg, end, compare);
    sort(beg, p, compare); sort(++p, end, compare);
}

int less(T *A, T *B) { return *A < *B; }