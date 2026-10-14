void fix(unsigned short*, int, int, int);
void sift(unsigned short* a, int i, int n, int x) {
    int orig = i;
    int child;
    while ((child = i * 2 + 2) < n) {
        if (a[child] < a[child - 1])
            --child;
        a[i] = a[child];
        i = child;
    }
    if (child == n) {
        a[i] = a[n - 1];
        i = n - 1;
    }
    fix(a, i, orig, x);
}