// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00188650 @ 0x00188650
#include "decls/data/game/hulkfight/motion.h"

void* __cdecl FUN_0008d690(unsigned int);
void* operator new(unsigned int, void* p) { return p; }
void FUN_001803e0(); void FUN_00180400(); void FUN_00180420();
namespace hulkfight { namespace motion { class PropDamageTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void v0(); char data[12]; void (*callback)(); int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void v0(); char data[12]; void (*callback)(); int tail;
 void FUN_002348e0(const char*);
};
}
 
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (!DAT_004e14dc) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack> F;
 typedef fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack> I;
 F* a=(F*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) F; a->callback=FUN_001803e0; } params[0]=a;
 I* b=(I*)FUN_0008d690(24);
 if(b) { b->FUN_002348e0("attachmentIndex"); new(b) I; b->callback=FUN_00180400; } params[1]=b;
 F* c=(F*)FUN_0008d690(24);
 if(c) { c->FUN_00234960("damage"); new(c) F; c->callback=FUN_00180420; } params[2]=c;
 FUN_002347b0(&DAT_004e14d8,params,3);
 }
 ++DAT_004e14dc;
}