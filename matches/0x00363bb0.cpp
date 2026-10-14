// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363bb0 {
    void f();
};
extern Obj_363bb0 g_363bb0;
void wrapper() {
    g_363bb0.f();
}