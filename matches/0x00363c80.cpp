// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363c80 {
    void f();
};
extern Obj_363c80 g_363c80;
void wrapper() {
    g_363c80.f();
}