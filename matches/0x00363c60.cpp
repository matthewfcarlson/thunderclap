// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363c60 {
    void f();
};
extern Obj_363c60 g_363c60;
void wrapper() {
    g_363c60.f();
}