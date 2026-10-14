// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_3645b0 {
    void f();
};
extern Obj_3645b0 g_3645b0;
void wrapper() {
    g_3645b0.f();
}