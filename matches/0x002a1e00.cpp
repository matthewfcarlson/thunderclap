typedef unsigned char(__cdecl* Compare_2a1e00)(int, int);
void Sort3(int* a, int* b, int* c, Compare_2a1e00 cmp) {
    if (cmp(*b, *a)) {
        int t = *b;
        *b = *a;
        *a = t;
    }
    if (cmp(*c, *b)) {
        int t = *c;
        *c = *b;
        *b = t;
    }
    if (cmp(*b, *a)) {
        int t = *b;
        *b = *a;
        *a = t;
    }
}