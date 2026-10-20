// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_0009bf50 @ 0x0009bf50
#include "gen/global.h"
struct Toggle { void FUN_000361c0(int); void FUN_00036140(int); };
struct Context_9bf50 { char pad[0x124]; Toggle* toggle; };
struct Arg_9bf50 { char pad[0x20]; Context_9bf50* context; };
struct CNISCamera_nv_9bf50 {
    CNISCamera* FUN_000ac3c0();
    void FUN_000ac560(void*);
};
struct Helper_9bf50 { void FUN_00098480(Arg_9bf50*); };
void* __cdecl FUN_00263ea0(unsigned);
struct Target_9bf50 {
 char pad0[4]; unsigned flags; char pad8[8]; unsigned value; unsigned saved; unsigned char busy; char pad19[0xbc-0x19]; Helper_9bf50* helper; CNISCamera* item;
 void FUN_0009a1e0(Arg_9bf50*); void FUN_000991b0(Arg_9bf50*,unsigned,CNISCamera*,int,int);
 void run(Arg_9bf50* arg, void* input);
};
void Target_9bf50::run(Arg_9bf50* arg, void* input) {
 if (!input || busy || (flags & 8) || (flags & 64)) return;
 if (flags & 2) FUN_0009a1e0(arg);
 if (flags & 0x5e) return;
 if (flags & 32) helper->FUN_00098480(arg);
 flags = (flags & ~32u) | 8;
 saved = value;
 if (!item) {
  CNISCamera* p = (CNISCamera*)FUN_00263ea0(0x178);
  if (p) p = ((CNISCamera_nv_9bf50*)(p))->FUN_000ac3c0();
  item = p;
  p->vfunc_0();
  item->vfunc_28();
 }
 ((CNISCamera_nv_9bf50*)(item))->FUN_000ac560(input);
 Toggle* toggle = arg->context->toggle;
 if (toggle) { toggle->FUN_000361c0(1); toggle->FUN_00036140(1); }
 FUN_000991b0(arg,value,item,0,0);
}
