// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3642e0 {
    void f();
};
extern Obj_3642e0 g_3642e0;
void wrapper() {
    g_3642e0.f();
}