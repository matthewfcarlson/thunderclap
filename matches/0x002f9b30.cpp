// Same code shape as 0x002a47d0 (propagated; names are from that function)
typedef unsigned int u32_2f9b30;
void __cdecl thunk_FUN_00267090(u32_2f9b30);
struct X_2f9b30 {
    u32_2f9b30 a;
    u32_2f9b30 b;
    void f();
};
void X_2f9b30::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}