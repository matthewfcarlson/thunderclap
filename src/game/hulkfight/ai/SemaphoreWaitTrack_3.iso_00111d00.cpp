// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"


// 0x00111d00 FUN_00111d00 (231 B): equivalent/0x00111d00.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: _FUN_00111d00 @5b288ede68fb @wb13d69ff88a0
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f48ab293 {} using namespace fn_f48ab293;
namespace fn_f48ab293 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_00111d00 @ 0x00111d00

extern bool SetCompare_0010c140(void*, int); /* (unb5) as defined; address taken only */ extern char SetValue_0010c170(void*, int); /* (unb5) as defined; address taken only */ extern void SetText_0010c8d0();
extern void* __cdecl FUN_0008d690(unsigned);
extern void __cdecl FUN_002347b0(void*,void*,int);

} // namespace fn_f48ab293
inline void* __cdecl operator new(size_t,void* p) { return p; }
namespace fn_f48ab293 {

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
extern "C" void FUN_00111d00() {
 if (!DAT_004e0afc) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition> E;
 typedef fight::ParamString<hulkfight::ai::AIHistoryNameCondition> S;
 typedef fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition> F;
 E* e=(E*)FUN_0008d690((int)sizeof(E));
 if(e) { int n=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new(e) E; e->count=n; e->values=((char*)&DAT_0042773c); e->callback=(void (*)())SetCompare_0010c140; }
 params[0]=e;
 S* s=(S*)FUN_0008d690((int)sizeof(S));
 if(s) { s->FUN_002349e0("text"); new(s) S; s->callback=SetText_0010c8d0; }
 params[1]=s;
 F* f=(F*)FUN_0008d690((int)sizeof(F));
 if(f) { f->FUN_00234960("value"); new(f) F; f->callback=(void (*)())SetValue_0010c170; }
 params[2]=f;
 FUN_002347b0(((int*)&DAT_004e0af8),params,3);
 }
 ++DAT_004e0afc;
}
} // namespace fn_f48ab293

