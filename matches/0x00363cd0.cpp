// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363cd0 {
    void f();
};
extern Obj_363cd0 g_363cd0;
void wrapper() {
    g_363cd0.f();
}