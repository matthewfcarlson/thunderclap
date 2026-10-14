// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_363f70 {
    void f();
};
extern Obj_363f70 g_363f70;
void wrapper() {
    g_363f70.f();
}