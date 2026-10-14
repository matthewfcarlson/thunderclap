// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ed0 {
    void f();
};
extern Obj_363ed0 g_363ed0;
void wrapper() {
    g_363ed0.f();
}