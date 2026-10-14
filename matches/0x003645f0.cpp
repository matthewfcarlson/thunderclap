// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3645f0 {
    void f();
};
extern Obj_3645f0 g_3645f0;
void wrapper() {
    g_3645f0.f();
}