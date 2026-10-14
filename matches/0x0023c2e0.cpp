// Same code shape as 0x00231960 (propagated; names are from that function)
extern void* vtable_23c2e0;
struct Sub_23c2e0 {
    void init();
};
struct Foo_23c2e0 {
    void* vt;
    char pad[0x24];
    void target();
    void finish();
};
void Foo_23c2e0::target() {
    vt = &vtable_23c2e0;
    ((Sub_23c2e0*)((char*)this + 0x28))->init();
    finish();
}
