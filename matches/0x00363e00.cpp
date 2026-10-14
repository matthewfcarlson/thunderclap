// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363e00 {
    void f();
};
extern Obj_363e00 g_363e00;
void wrapper() {
    g_363e00.f();
}