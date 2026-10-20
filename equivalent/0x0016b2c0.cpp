// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_0016b2c0 @ 0x0016b2c0
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

typedef unsigned int size_t;
void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(size_t, void* p) { return p; }
void FUN_00165540(); void FUN_00165550(); void FUN_00165560(); void FUN_00165570();
namespace hulkfight { namespace motion { class IntentionInputCondition; } }
namespace fight {
template<class T> struct ParamBool {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int tail;
 void FUN_00234860(const char*);
};
}
typedef fight::ParamBool<hulkfight::motion::IntentionInputCondition> Param;
void __cdecl FUN_002347b0(void*, Param**, int);
void target() {
 if (!DAT_004e121c) {
 Param* list[4];
 const char* names[4] = {"buttonDown", "buttonPressed", "axisDown", "axisPressed"};
 void (*callbacks[4])() = {FUN_00165540,FUN_00165550,FUN_00165560,FUN_00165570};
 for(int i=0;i<4;++i) {
 void* memory=FUN_0008d690(24);
 if(memory) {
 Param* p=(Param*)memory;
 p->FUN_00234860(names[i]);
 p=new(memory) Param;
 p->callback=callbacks[i];
 list[i]=p;
 } else list[i]=0;
 }
 FUN_002347b0(&DAT_004e1218,list,4);
 }
 ++DAT_004e121c;
}