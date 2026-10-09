typedef unsigned int u32;
void __cdecl thunk_FUN_00267090(u32);
struct X {
    u32 a;
    u32 b;
    void f();
};
void X::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}