struct E_1e2800 {
    int a, b, c, d, e;
};
void Sift(E_1e2800* base, int idx, int n, E_1e2800 v);
void Heapify(E_1e2800* first, E_1e2800* last) {
    int n = (last - first);
    int i = n / 2;
    if (i > 0) {
        E_1e2800* p = first + i;
        do {
            i--;
            Sift(first, i, n, *--p);
        } while (i > 0);
    }
}
