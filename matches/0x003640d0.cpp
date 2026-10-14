// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3640d0 {
    void f();
};
extern Obj_3640d0 g_3640d0;
void wrapper() {
    g_3640d0.f();
}