// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364420 {
    void f();
};
extern Obj_364420 g_364420;
void wrapper() {
    g_364420.f();
}