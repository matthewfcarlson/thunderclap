extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c8b4[];
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
    vf = ((int)DAT_0042c8b4);
    thunk(a);
    thunk(b);
    vf = ((int)DAT_003f6098);
}
