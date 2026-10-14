// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363bc0 {
    void f();
};
extern Obj_363bc0 g_363bc0;
void wrapper() {
    g_363bc0.f();
}