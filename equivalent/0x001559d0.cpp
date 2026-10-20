// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_001559d0 @ 0x001559d0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned,void* p) { return p; }
namespace hulkfight { namespace motion { class CollisionDamageHealthCompareCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* list; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
}
void FUN_0014c6b0(); void FUN_0014c6d0(); void FUN_0014c6e0(); void FUN_0014c700();
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_002347b0(void*,void**,int);
void FUN_001559d0() {
 if (!DAT_004e10b4) {
 void* objects[4];
 typedef hulkfight::motion::CollisionDamageHealthCompareCondition T;
 fight::ParamEnumConstList<T>* a=(fight::ParamEnumConstList<T>*)FUN_0008d690(32);
 if(a) { int n=(*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); new(a) fight::ParamEnumConstList<T>; a->list=DAT_0042773c; a->count=n; a->callback=FUN_0014c6b0; }
 objects[0]=a;
 fight::ParamFloatConstRange<T>* b=(fight::ParamFloatConstRange<T>*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("damage"); new(b) fight::ParamFloatConstRange<T>; b->callback=FUN_0014c6d0; } objects[1]=b;
 fight::ParamFloatConstRange<T>* c=(fight::ParamFloatConstRange<T>*)FUN_0008d690(24);
 if(c) { c->FUN_00234960("percent"); new(c) fight::ParamFloatConstRange<T>; c->callback=FUN_0014c6e0; } objects[2]=c;
 fight::ParamBool<T>* d=(fight::ParamBool<T>*)FUN_0008d690(24);
 if(d) { d->FUN_00234860("compareVsHealthPercent"); new(d) fight::ParamBool<T>; d->callback=FUN_0014c700; } objects[3]=d;
 FUN_002347b0(((int*)&DAT_004e10b0),objects,4);
 }
 ++DAT_004e10b4;
}