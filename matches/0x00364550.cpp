// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364550 {
    void f();
};
extern Obj_364550 g_364550;
void wrapper() {
    g_364550.f();
}