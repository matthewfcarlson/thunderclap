// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ca0 {
    void f();
};
extern Obj_363ca0 g_363ca0;
void wrapper() {
    g_363ca0.f();
}