typedef unsigned int u32;
typedef unsigned char u8;
extern u32 __cdecl Find(u32, u32);
extern u32 __cdecl Create(u32, u32);
extern void __cdecl Use(u32);
extern void __cdecl Finish(u32, u32, u32, u32, u32);
class Obj {
public:
 char pad0[4];
 u32 mArg;
 char pad8[16];
 u32 mResult;
 u8 mFlag;
 void Run(u32);
};
void Obj::Run(u32 arg) {
 u32 x = Find(mArg, arg);
 if (x && !mResult) {
  mFlag = 0;
  u32 y = Create(mArg, x);
  mResult = y;
  Use(y);
  Finish(mArg, mResult, 0, 1, 0);
 }
}