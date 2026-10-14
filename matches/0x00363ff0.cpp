// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ff0 {
    void f();
};
extern Obj_363ff0 g_363ff0;
void wrapper() {
    g_363ff0.f();
}