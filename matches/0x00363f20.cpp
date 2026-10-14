// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363f20 {
    void f();
};
extern Obj_363f20 g_363f20;
void wrapper() {
    g_363f20.f();
}