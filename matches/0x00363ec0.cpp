// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363ec0 {
    void f();
};
extern Obj_363ec0 g_363ec0;
void wrapper() {
    g_363ec0.f();
}