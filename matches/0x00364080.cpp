// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364080 {
    void f();
};
extern Obj_364080 g_364080;
void wrapper() {
    g_364080.f();
}