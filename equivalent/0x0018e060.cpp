// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0018e060 @ 0x0018e060
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_0018cb80(); void __cdecl FUN_0018cba0(); void __cdecl FUN_0018cbc0();
namespace hulkfight { namespace motion { class TimerSetTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002348e0(const char*); };
}
 
void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_0018e060() {
 if (!DAT_004e1524) {
  void* params[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::TimerSetTrack> F;
  typedef fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack> I;
  F* a=(F*)FUN_0008d690(24);
  if(a) { a->FUN_00234960("timeBegin"); a=new(a) F; a->callback=FUN_0018cb80; }
  params[0]=a;
  I* b=(I*)FUN_0008d690(24);
  if(b) { b->FUN_002348e0("timer"); b=new(b) I; b->callback=FUN_0018cba0; }
  params[1]=b;
  F* c=(F*)FUN_0008d690(24);
  if(c) { c->FUN_00234960("value"); c=new(c) F; c->callback=FUN_0018cbc0; }
  params[2]=c;
  FUN_002347b0(&DAT_004e1520,params,3);
 }
 ++DAT_004e1524;
}
