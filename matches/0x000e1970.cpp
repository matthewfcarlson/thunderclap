typedef unsigned int u32;
class FEDoSound {
  public:
    int vtable;
    int pad4;
    int a;
    int b;
    int c;
    char flag;
    char pad15[0x1f];
    char name[0x20];
    FEDoSound* Init(u32, const char*);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, const char*);
extern const char DAT_003f3f38;
FEDoSound* FEDoSound::Init(u32 param_2, const char* param_3) {
    a = -1;
    b = -1;
    c = param_2;
    flag = 0;
    vtable = 0x40c02c;
    FUN_000dfcc0(name, 0x20, &DAT_003f3f38, param_3);
    return this;
}