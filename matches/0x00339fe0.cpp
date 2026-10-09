int Compare(int, int);
int Build(int, int);
int Target(int a, int b, int c) {
    int r = Compare(a, b);
    if (r <= 0)
        return c;
    return Build(a, b);
}