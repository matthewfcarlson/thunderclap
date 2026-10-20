// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0005c490 @ 0x0005c490
#include "compat/ptr.h"
#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_0005a330();
void __cdecl FUN_0005a340();
void __cdecl FUN_0005a350();
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
class CGrappleSequenceTrack;
struct FUN_00235170 {
 FUN_00235170(const char* = "branch");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
struct FUN_002348e0 {
 FUN_002348e0(const char* = "priority");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
struct FUN_00235220 {
 FUN_00235220(const char* = "conditionGroup");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
namespace fight {
 template<class T> struct ParamBranch : FUN_00235170 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
 template<class T> struct ParamConditionGroup : FUN_00235220 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(void**,void**,int);
void __cdecl FUN_0005c490() {
 if (!DAT_004dc5bc) {
  void* entries[3];
  void* mem = FUN_0008d690(24);
  fight::ParamBranch<CGrappleSequenceTrack>* a = mem ? new(mem) fight::ParamBranch<CGrappleSequenceTrack> : 0;
  if(a) a->callback = FUN_0005a330;
  entries[0]=a;
  mem = FUN_0008d690(24);
  fight::ParamIntConstRange<CGrappleSequenceTrack>* b = mem ? new(mem) fight::ParamIntConstRange<CGrappleSequenceTrack> : 0;
  if(b) b->callback = FUN_0005a340;
  entries[1]=b;
  mem = FUN_0008d690(24);
  fight::ParamConditionGroup<CGrappleSequenceTrack>* c = mem ? new(mem) fight::ParamConditionGroup<CGrappleSequenceTrack> : 0;
  if(c) c->callback = FUN_0005a350;
  entries[2]=c;
  FUN_002347b0(((void**)&DAT_004dc5b8),entries,3);
 }
 ++DAT_004dc5bc;
}