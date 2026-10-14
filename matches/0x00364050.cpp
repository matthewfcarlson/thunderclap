// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364050 {
    void f();
};
extern Obj_364050 g_364050;
void wrapper() {
    g_364050.f();
}