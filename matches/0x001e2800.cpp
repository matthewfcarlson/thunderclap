struct E {
    int a, b, c, d, e;
};
void Sift(E* base, int idx, int n, E v);
void Heapify(E* first, E* last) {
    int n = (last - first);
    int i = n / 2;
    if (i > 0) {
        E* p = first + i;
        do {
            i--;
            Sift(first, i, n, *--p);
        } while (i > 0);
    }
}
