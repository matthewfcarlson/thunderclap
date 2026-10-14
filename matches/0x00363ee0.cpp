// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ee0 {
    void f();
};
extern Obj_363ee0 g_363ee0;
void wrapper() {
    g_363ee0.f();
}