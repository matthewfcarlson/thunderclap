// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364300 {
    void f();
};
extern Obj_364300 g_364300;
void wrapper() {
    g_364300.f();
}