// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363c70 {
    void f();
};
extern Obj_363c70 g_363c70;
void wrapper() {
    g_363c70.f();
}