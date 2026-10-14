// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363fa0 {
    void f();
};
extern Obj_363fa0 g_363fa0;
void wrapper() {
    g_363fa0.f();
}