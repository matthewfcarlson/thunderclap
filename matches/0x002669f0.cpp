typedef unsigned int u32;
class Thing {
  public:
    char pad0[0x280];
    int mIndex;
    int mArg;
};
extern u32 __fastcall GetValue(int);
u32 __fastcall FUN_002669f0(Thing* self) {
    u32* p = (u32*)((char*)self + (self->mIndex + 8) * 16);
    if (p[2] > p[1]) {
        u32 value = GetValue(self->mArg);
        if (value < p[3] + p[2])
            return 1;
    }
    return 0;
}