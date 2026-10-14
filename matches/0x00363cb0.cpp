// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363cb0 {
    void f();
};
extern Obj_363cb0 g_363cb0;
void wrapper() {
    g_363cb0.f();
}