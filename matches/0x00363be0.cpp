// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363be0 {
    void f();
};
extern Obj_363be0 g_363be0;
void wrapper() {
    g_363be0.f();
}