// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3642f0 {
    void f();
};
extern Obj_3642f0 g_3642f0;
void wrapper() {
    g_3642f0.f();
}