// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ef0 {
    void f();
};
extern Obj_363ef0 g_363ef0;
void wrapper() {
    g_363ef0.f();
}