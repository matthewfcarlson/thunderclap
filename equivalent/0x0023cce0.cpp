// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_0023cce0 @ 0x0023cce0
#include "decls/data/engine/fight.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0023cb40();
void __cdecl FUN_0023cb50();
void __cdecl FUN_0023cb60();
void __cdecl FUN_0023cb70();
namespace fight {
class PlatformCondition;
template<class T> struct ParamBool {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_00234860(const char*);
};
}
void __cdecl FUN_002347b0(int*, fight::ParamBool<fight::PlatformCondition>**, int);
void __cdecl FUN_0023cce0() {
 if (DAT_004e5c50 == 0) {
 typedef fight::ParamBool<fight::PlatformCondition> P;
 P* items[4];
 P* p = (P*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("pS2"); new (p) P; p->callback = FUN_0023cb40; }
 items[0]=p;
 p=(P*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("xBox"); new (p) P; p->callback = FUN_0023cb50; }
 items[1]=p;
 p=(P*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("gameCube"); new (p) P; p->callback = FUN_0023cb60; }
 items[2]=p;
 p=(P*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("win32"); new (p) P; p->callback = FUN_0023cb70; }
 items[3]=p;
 FUN_002347b0(&DAT_004e5c4c,items,4);
 }
 ++DAT_004e5c50;
}
