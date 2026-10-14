// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3641b0 {
    void f();
};
extern Obj_3641b0 g_3641b0;
void wrapper() {
    g_3641b0.f();
}