typedef unsigned int u32;
void thunk(u32);
struct X {
    u32 vf;
    char pad[0x14];
    u32 a;
    u32 b;
    void target();
};
void X::target() {
    vf = 0x42c8b4;
    thunk(a);
    thunk(b);
    vf = 0x3f6098;
}
