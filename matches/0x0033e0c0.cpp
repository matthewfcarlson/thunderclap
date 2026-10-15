extern "C" int F1(int, int, int, int);
extern "C" int F2(int);
extern "C" int F3(int, int);
extern "C" void F4(int);
extern "C" void F5(int, int, int);
int f(int x) {
    int a = F1(x, 1, 0, 0);
    int b = F2(x);
    if (F3(x, a))
        F4(x);
    F5(x, 0, -1);
    return F2(x) - b;
}