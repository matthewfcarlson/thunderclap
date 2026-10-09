extern int f212d70(int);
extern int f339010(int, int, int);
extern void f212ed0(int, int);
extern void f2139a0(int, int, int);
int target(int a, int b, int c) {
    if (b <= 0 && b > -10000)
        b = b + 1 + f212d70(a);
    if (f339010(a, b, c) == 0)
        return 0;
    f212ed0(a, b);
    f2139a0(a, 1, 1);
    return 1;
}