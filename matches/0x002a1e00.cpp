typedef unsigned char (__cdecl *Compare)(int, int);
void Sort3(int *a, int *b, int *c, Compare cmp) {
    if (cmp(*b, *a)) { int t = *b; *b = *a; *a = t; }
    if (cmp(*c, *b)) { int t = *c; *c = *b; *b = t; }
    if (cmp(*b, *a)) { int t = *b; *b = *a; *a = t; }
}