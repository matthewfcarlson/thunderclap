// Same code shape as 0x00363af0 (propagated; names are from that function)
struct CStaticAllocator_364010 {
    void f();
};
extern CStaticAllocator_364010 g_364010;
void wrapper() {
    g_364010.f();
}