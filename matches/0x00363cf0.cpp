// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363cf0 {
    void f();
};
extern Obj_363cf0 g_363cf0;
void wrapper() {
    g_363cf0.f();
}