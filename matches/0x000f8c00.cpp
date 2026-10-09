class C {
  public:
    int pad;
    int a[128];
    int f(int x);
};
int C::f(int x) {
    int i = 0;
    do {
        if (a[i] == 0)
            break;
        if (i == 128)
            return 0;
        ++i;
    } while (i < 128);
    a[i] = x;
    return x;
}