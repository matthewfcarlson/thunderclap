// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363f80 {
    void f();
};
extern Obj_363f80 g_363f80;
void wrapper() {
    g_363f80.f();
}