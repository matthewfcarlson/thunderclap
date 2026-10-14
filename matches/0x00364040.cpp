// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364040 {
    void f();
};
extern Obj_364040 g_364040;
void wrapper() {
    g_364040.f();
}