extern "C" int __cdecl A(int, int, int*);
extern "C" int __cdecl B(int, int, int, int);
extern "C" int __cdecl C(int, int, int, int);
extern "C" void __cdecl D(int);
extern "C" void __cdecl E(int, int);
int __cdecl FUN_0033ded0(int x) {
    int t;
    int a = A(x, 1, &t);
    int b = B(x, 2, a, 0);
    if (!C(x, a, t, b))
        return 1;
    D(x);
    E(x, -2);
    return 2;
}