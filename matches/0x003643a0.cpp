// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3643a0 {
    void f();
};
extern Obj_3643a0 g_3643a0;
void wrapper() {
    g_3643a0.f();
}