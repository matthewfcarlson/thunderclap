// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363fd0 {
    void f();
};
extern Obj_363fd0 g_363fd0;
void wrapper() {
    g_363fd0.f();
}