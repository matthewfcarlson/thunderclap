// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363e20 {
    void f();
};
extern Obj_363e20 g_363e20;
void wrapper() {
    g_363e20.f();
}