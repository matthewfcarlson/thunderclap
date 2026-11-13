// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"


// 0x00131720 FUN_00131720 (290 B): equivalent/0x00131720.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_00131720@fn_fb1b4050@@YAXXZ @ff35fd720b0f @w2b881fab269f
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight.h"
namespace fn_fb1b4050 {} using namespace fn_fb1b4050;
namespace fn_fb1b4050 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_00131720 @ 0x00131720

/* size_t: tree_prelude.h */

} // namespace fn_fb1b4050
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fb1b4050 {

namespace hulkfight { class ChapterMissionCondition; }
void* __cdecl FUN_0008d690(unsigned int);
bool FUN_0012e050(void*, int); /* (unb4) as defined; address taken only */ char FUN_0012e060(void*, int); /* (unb4) as defined; address taken only */ char FUN_0012e080(void*, int); /* (unb4) as defined; address taken only */ char FUN_0012e090(void*, int); /* (unb4) as defined; address taken only */
void __cdecl FUN_002347b0(void*,void*,int);
struct FUN_00234cc0 { virtual void slot0(); char base[12]; FUN_00234cc0(const char*); };
struct FUN_002348e0 { virtual void slot0(); char base[12]; FUN_002348e0(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 virtual void slot0();
 const char* values; int count; void (*callback)(); int tail;
 ParamEnumConstList(const char* s) : FUN_00234cc0(s) {}
};
template<class T> struct ParamIntConstRange : FUN_002348e0 {
 virtual void slot0();
 void (*callback)(); int tail;
 ParamIntConstRange(const char* s) : FUN_002348e0(s) {}
};
}
typedef fight::ParamEnumConstList<hulkfight::ChapterMissionCondition> Enum_131720;
typedef fight::ParamIntConstRange<hulkfight::ChapterMissionCondition> Range_131720;
void FUN_00131720() {
 if ((*(int*)&DAT_004e0e78) == 0) {
  void* list[4];
  Enum_131720* a=(Enum_131720*)FUN_0008d690((int)sizeof(Enum_131720));
  if(a) { int count=(*(int*)&DAT_00427754); a=new(a) Enum_131720("chapterCompare"); a->values="lwB"; a->count=count; a->callback=(void (*)())FUN_0012e050; } list[0]=a;
  Range_131720* b=(Range_131720*)FUN_0008d690((int)sizeof(Range_131720));
  if(b) { b=new(b) Range_131720("chapter"); b->callback=(void (*)())FUN_0012e060; } list[1]=b;
  Enum_131720* c=(Enum_131720*)FUN_0008d690((int)sizeof(Enum_131720));
  if(c) { int count=(*(int*)&DAT_00427754); c=new(c) Enum_131720("missionCompare"); c->values="lwB"; c->count=count; c->callback=(void (*)())FUN_0012e080; } list[2]=c;
  Range_131720* d=(Range_131720*)FUN_0008d690((int)sizeof(Range_131720));
  if(d) { d=new(d) Range_131720("mission"); d->callback=(void (*)())FUN_0012e090; } list[3]=d;
  FUN_002347b0(((int*)&DAT_004e0e74),list,4);
 }
 ++(*(int*)&DAT_004e0e78);
}
} // namespace fn_fb1b4050

