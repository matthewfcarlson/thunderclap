// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364400 {
    void f();
};
extern Obj_364400 g_364400;
void wrapper() {
    g_364400.f();
}