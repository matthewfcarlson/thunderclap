// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363fb0 {
    void f();
};
extern Obj_363fb0 g_363fb0;
void wrapper() {
    g_363fb0.f();
}