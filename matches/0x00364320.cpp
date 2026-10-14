// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364320 {
    void f();
};
extern Obj_364320 g_364320;
void wrapper() {
    g_364320.f();
}