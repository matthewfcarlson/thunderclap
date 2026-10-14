// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364270 {
    void f();
};
extern Obj_364270 g_364270;
void wrapper() {
    g_364270.f();
}