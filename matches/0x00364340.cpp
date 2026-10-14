// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364340 {
    void f();
};
extern Obj_364340 g_364340;
void wrapper() {
    g_364340.f();
}