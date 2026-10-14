typedef unsigned int u32_2a47d0;
void __cdecl thunk_FUN_00267090(u32_2a47d0);
struct X_2a47d0 {
    u32_2a47d0 a;
    u32_2a47d0 b;
    void f();
};
void X_2a47d0::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}