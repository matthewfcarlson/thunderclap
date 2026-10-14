// Same code shape as 0x002a47d0 (propagated; names are from that function)
typedef unsigned int u32_2a7fd0;
void __cdecl thunk_FUN_00267090(u32_2a7fd0);
struct X_2a7fd0 {
    u32_2a7fd0 a;
    u32_2a7fd0 b;
    void f();
};
void X_2a7fd0::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}