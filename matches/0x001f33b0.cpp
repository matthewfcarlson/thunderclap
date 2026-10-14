typedef unsigned int u32_1f33b0;
typedef unsigned char u8;
extern u32_1f33b0 __cdecl Find(u32_1f33b0, u32_1f33b0);
extern u32_1f33b0 __cdecl Create(u32_1f33b0, u32_1f33b0);
extern void __cdecl Use(u32_1f33b0);
extern void __cdecl Finish(u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0);
class Obj_1f33b0 {
  public:
    char pad0[4];
    u32_1f33b0 mArg;
    char pad8[16];
    u32_1f33b0 mResult;
    u8 mFlag;
    void Run(u32_1f33b0);
};
void Obj_1f33b0::Run(u32_1f33b0 arg) {
    u32_1f33b0 x = Find(mArg, arg);
    if (x && !mResult) {
        mFlag = 0;
        u32_1f33b0 y = Create(mArg, x);
        mResult = y;
        Use(y);
        Finish(mArg, mResult, 0, 1, 0);
    }
}