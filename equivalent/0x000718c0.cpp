// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_000718c0 @ 0x000718c0
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
class CComboTimerTrack;
void __cdecl FUN_00068550();
void __cdecl FUN_00068560();
void __cdecl FUN_00068570();
struct ParamBase {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char* name);
};
namespace fight {
 template<class T> struct ParamFloatConstRange : ParamBase {
 virtual void slot0();
 };
}
extern unsigned int DAT_004dcf84;
extern unsigned int DAT_004dcf80;
void* __cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_002347b0(void* registry, ParamBase** params, int count);
void __cdecl FUN_000718c0() {
 if (!DAT_004dcf84) {
  ParamBase* params[3];
  ParamBase* p = (ParamBase*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("timeBegin");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068550;
  }
  params[0] = p;
  p = (ParamBase*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("timeEnd");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068560;
  }
  params[1] = p;
  p = (ParamBase*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("comboTimer");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068570;
  }
  params[2] = p;
  FUN_002347b0(&DAT_004dcf80, params, 3);
 }
 ++DAT_004dcf84;
}
