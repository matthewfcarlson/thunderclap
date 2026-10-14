// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363b90 {
    void f();
};
extern Obj_363b90 g_363b90;
void wrapper() {
    g_363b90.f();
}