// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363b60 {
    void f();
};
extern Obj_363b60 g_363b60;
void wrapper() {
    g_363b60.f();
}