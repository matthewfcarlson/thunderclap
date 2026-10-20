// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_00111d00 @ 0x00111d00
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

extern void FUN_0010c140(); extern void FUN_0010c170(); extern void FUN_0010c8d0();
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern void __cdecl FUN_002347b0(void*,void*,int);
inline void* __cdecl operator new(unsigned,void* p) { return p; }
struct Base_111d00 {
 virtual void slot0();
 char pad[12];
 void FUN_00234cc0(const char*);
 void FUN_002349e0(const char*);
 void FUN_00234960(const char*);
};
namespace hulkfight { namespace ai { class AIHistoryNameCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList : Base_111d00 { virtual void slot0(); char* values; int count; void (*callback)(); char tail[4]; };
template<class T> struct ParamString : Base_111d00 { virtual void slot0(); void (*callback)(); char tail[4]; };
template<class T> struct ParamFloatConstRange : Base_111d00 { virtual void slot0(); void (*callback)(); char tail[4]; };
}
void FUN_00111d00() {
 if (!DAT_004e0afc) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition> E;
 typedef fight::ParamString<hulkfight::ai::AIHistoryNameCondition> S;
 typedef fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition> F;
 E* e=(E*)FUN_0008d690(32);
 if(e) { int n=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new(e) E; e->count=n; e->values=((char*)&DAT_0042773c); e->callback=FUN_0010c140; }
 params[0]=e;
 S* s=(S*)FUN_0008d690(24);
 if(s) { s->FUN_002349e0("text"); new(s) S; s->callback=FUN_0010c8d0; }
 params[1]=s;
 F* f=(F*)FUN_0008d690(24);
 if(f) { f->FUN_00234960("value"); new(f) F; f->callback=FUN_0010c170; }
 params[2]=f;
 FUN_002347b0(((int*)&DAT_004e0af8),params,3);
 }
 ++DAT_004e0afc;
}
