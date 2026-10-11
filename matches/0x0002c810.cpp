extern "C" char DAT_003f408c[];
typedef unsigned char u8;
typedef unsigned int u32;
void __stdcall setup(void*, int);
u8 __cdecl getval(const void*);
extern char g1[];
extern char g2[];
extern char g3[];
extern char g4[];
class Method3 {
  public:
    u32 vf;
    char pad4[12];
    u8 b10, b11, b12;
    char pad13[5];
    u8 b18;
    char pad19[3];
    u32 value;
    Method3* target(void*, u32);
};
Method3* Method3::target(void* a, u32 c) {
    setup(a, 3);
    vf = ((int)DAT_003f408c);
    value = c;
    b18 = getval(g1);
    b10 = getval(g2);
    b11 = getval(g3);
    b12 = getval(g4);
    return this;
}