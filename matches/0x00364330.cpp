// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364330 {
    void f();
};
extern Obj_364330 g_364330;
void wrapper() {
    g_364330.f();
}