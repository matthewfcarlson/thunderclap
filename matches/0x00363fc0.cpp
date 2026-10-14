// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363fc0 {
    void f();
};
extern Obj_363fc0 g_363fc0;
void wrapper() {
    g_363fc0.f();
}