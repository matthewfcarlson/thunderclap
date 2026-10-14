// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364090 {
    void f();
};
extern Obj_364090 g_364090;
void wrapper() {
    g_364090.f();
}