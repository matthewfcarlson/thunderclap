// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364120 {
    void f();
};
extern Obj_364120 g_364120;
void wrapper() {
    g_364120.f();
}