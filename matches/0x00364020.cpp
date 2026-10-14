// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj_364020 {
    void f();
};
extern Obj_364020 g_364020;
void wrapper() {
    g_364020.f();
}