typedef unsigned int u32_1f33b0;
typedef unsigned char u8;
extern u32_1f33b0 __cdecl Find(u32_1f33b0, u32_1f33b0);
extern "C" u32_1f33b0 __cdecl FUN_0024a9c0(u32_1f33b0, u32_1f33b0);
extern "C" void __cdecl FUN_00247a10(u32_1f33b0);
extern "C" void __cdecl FUN_00247a20(u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0);
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
        u32_1f33b0 y = FUN_0024a9c0(mArg, x);
        mResult = y;
        FUN_00247a10(y);
        FUN_00247a20(mArg, mResult, 0, 1, 0);
    }
}