// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001122b0 @ 0x001122b0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

typedef unsigned size_t;
inline void* operator new(size_t,void* p) { return p; }
namespace hulkfight { namespace ai { class HulkActionCountCondition; } }
void FUN_0010c280(); void FUN_0010c2b0(); void FUN_0010ce60();
   
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_002347b0(void*,void*,int);
struct BaseEnum_1122b0 { virtual void slot0(); char pad[12]; void FUN_00234cc0(const char*); };
struct BaseString { virtual void slot0(); char pad[12]; void FUN_002349e0(const char*); };
struct BaseFloat_1122b0 { virtual void slot0(); char pad[12]; void FUN_00234960(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : BaseEnum_1122b0 { const char* list; int count; void (*callback)(); int other; virtual void slot0(); };
template<class T> struct ParamString : BaseString { void (*callback)(); int other; virtual void slot0(); };
template<class T> struct ParamFloatConstRange : BaseFloat_1122b0 { void (*callback)(); int other; virtual void slot0(); };
}
void FUN_001122b0() {
 if (!DAT_004e0b3c) {
 void* items[3];
 typedef fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition> E;
 typedef fight::ParamString<hulkfight::ai::HulkActionCountCondition> S;
 typedef fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition> F;
 E* e=(E*)FUN_0008d690(32);
 if(e) { int n=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new(e) E; e->count=n; e->list=((char*)&DAT_0042773c); e->callback=FUN_0010c280; } items[0]=e;
 S* s=(S*)FUN_0008d690(24); if(s) { s->FUN_002349e0("text"); new(s) S; s->callback=FUN_0010ce60; } items[1]=s;
 F* f=(F*)FUN_0008d690(24); if(f) { f->FUN_00234960("value"); new(f) F; f->callback=FUN_0010c2b0; } items[2]=f;
 FUN_002347b0(&DAT_004e0b38,items,3);
 } ++DAT_004e0b3c;
}
