// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363bd0 {
    void f();
};
extern Obj_363bd0 g_363bd0;
void wrapper() {
    g_363bd0.f();
}