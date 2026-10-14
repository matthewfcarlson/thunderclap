// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363df0 {
    void f();
};
extern Obj_363df0 g_363df0;
void wrapper() {
    g_363df0.f();
}