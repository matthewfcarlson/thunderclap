// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_000548b0 @ 0x000548b0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00048200();
void __cdecl FUN_00048220();
void __cdecl FUN_00048240();
class CMotionClimbAngleCondition;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<CMotionClimbAngleCondition> Param;
extern unsigned int DAT_004dc584;
extern unsigned int DAT_004dc580;
void __cdecl FUN_002347b0(void*, Param**, int);
void __cdecl FUN_000548b0() {
 if (DAT_004dc584 == 0) {
  Param* params[3];
  Param* p = (Param*)FUN_0008d690(24);
  if(p) {p->FUN_00234960("angle"); new(p) Param; p->callback = FUN_00048200;} params[0]=p;
  p = (Param*)FUN_0008d690(24);
  if(p) {p->FUN_00234960("arc"); new(p) Param; p->callback = FUN_00048220;} params[1]=p;
  p = (Param*)FUN_0008d690(24);
  if(p) {p->FUN_00234960("minVelocity"); new(p) Param; p->callback = FUN_00048240;} params[2]=p;
  FUN_002347b0(&DAT_004dc580, params, 3);
 }
 ++DAT_004dc584;
}
