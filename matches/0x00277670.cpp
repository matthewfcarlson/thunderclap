struct X {
    char pad[0x14];
    int a;
    int b;
    int refs;
    int arg;
    void f();
};
extern void __cdecl helper(int, int);
void X::f() {
    if (refs == 1) {
        helper(arg, a);
        a = 0;
        b = 0;
    }
    --refs;
}