// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3645d0 {
    void f();
};
extern Obj_3645d0 g_3645d0;
void wrapper() {
    g_3645d0.f();
}