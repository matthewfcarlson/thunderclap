// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364000 {
    void f();
};
extern Obj_364000 g_364000;
void wrapper() {
    g_364000.f();
}