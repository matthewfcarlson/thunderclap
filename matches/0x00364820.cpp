// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364820 {
    void f();
};
extern Obj_364820 g_364820;
void wrapper() {
    g_364820.f();
}