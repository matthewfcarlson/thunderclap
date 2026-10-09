typedef char(__cdecl* Cmp)(int, int);
void Fix(int*, int, int, int, Cmp);
void Target(int* a, int b, int c, int d, Cmp fn) {
    int original = b;
    int i = b * 2 + 2;
    while (i < c) {
        if (fn(a[i], a[i - 1]))
            --i;
        a[b] = a[i];
        b = i;
        i = b * 2 + 2;
    }
    if (i == c) {
        a[b] = a[c - 1];
        b = c - 1;
    }
    Fix(a, b, original, d, fn);
}