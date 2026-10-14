// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ba0 {
    void f();
};
extern Obj_363ba0 g_363ba0;
void wrapper() {
    g_363ba0.f();
}