class C_26e430 {
    char pad[0x68];

  public:
    void f(int);
    void next(void*, int);
};
extern void __cdecl helper(void*, void*, int, int);
struct S_26e430 {
    int a, b;
};
void C_26e430::f(int p) {
    S_26e430 s;
    s.a = 8;
    s.b = p;
    helper(pad + 0x68, &s, 8, 0);
    next(&s, 8);
}