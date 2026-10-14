typedef unsigned int u32_2669f0;
class Thing_2669f0 {
  public:
    char pad0[0x280];
    int mIndex;
    int mArg;
};
extern u32_2669f0 __fastcall GetValue(int);
u32_2669f0 __fastcall FUN_002669f0(Thing_2669f0* self) {
    u32_2669f0* p = (u32_2669f0*)((char*)self + (self->mIndex + 8) * 16);
    if (p[2] > p[1]) {
        u32_2669f0 value = GetValue(self->mArg);
        if (value < p[3] + p[2])
            return 1;
    }
    return 0;
}