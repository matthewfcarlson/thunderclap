// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017a260 @ 0x0017a260
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0016f1c0(); void __cdecl FUN_0016f1d0(); void __cdecl FUN_0016f1f0();
namespace hulkfight { namespace motion { class MotionStateTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int tail; void FUN_00234960(const char*); };
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* values; unsigned int count; void (__cdecl *callback)(); unsigned int tail; void FUN_00234cc0(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*,void**,unsigned int);
void __cdecl FUN_0017a260() {
 if ((*(unsigned int*)&DAT_004e1344) == 0) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack> FloatParam;
 typedef fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack> EnumParam;
 FloatParam* a=(FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) FloatParam; a->callback=FUN_0016f1c0; }
 params[0]=a;
 FloatParam* b=(FloatParam*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("timeEnd"); new(b) FloatParam; b->callback=FUN_0016f1d0; }
 params[1]=b;
 EnumParam* c=(EnumParam*)FUN_0008d690(32);
 if(c) { unsigned int count=(*(unsigned int*)&DAT_003f5bb8); c->FUN_00234cc0("motionState"); new(c) EnumParam; c->values="0\\?"; c->count=count; c->callback=FUN_0016f1f0; }
 params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1340),params,3);
 }
 ++(*(unsigned int*)&DAT_004e1344);
}