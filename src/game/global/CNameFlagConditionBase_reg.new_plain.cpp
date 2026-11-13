// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f4b51f75 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4b51f75 {} using namespace fn_f4b51f75;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4b51f75 {
extern "C" void* __cdecl FUN_0008d690(unsigned);
char FUN_00047ab0(void*, int); /* (unb4) as defined; address taken only */
char FUN_00047ac0(void*, int); /* (unb4) as defined; address taken only */
char FUN_00047ad0(void*, int); /* (unb4) as defined; address taken only */
class CButtonCondition;
struct FUN_00234cc0 {
 virtual void slot0(); char pad[12];
 FUN_00234cc0(const char*);
};
struct FUN_00234960 {
 virtual void slot0(); char pad[12];
 FUN_00234960(const char*);
};
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 void* list; unsigned count; void (__cdecl *callback)(); unsigned tail;
 virtual void slot0();
 ParamEnumConstList(const char* name) : FUN_00234cc0(name) {}
};
}
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 {
 void (__cdecl *callback)(); unsigned tail;
 virtual void slot0();
 ParamFloatConstRange(const char* name) : FUN_00234960(name) {}
};
}
} // namespace fn_f4b51f75
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f4b51f75 {
extern "C" void __cdecl FUN_002347b0(unsigned*, void**, unsigned);


// 0x000527d0 FUN_000527d0 (245 B): equivalent/0x000527d0.cpp
// sym: _FUN_000527d0 @d3f46395cd35 @w96d0eacd6fd6
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_000527d0 @ 0x000527d0
extern "C" void __cdecl FUN_000527d0() {
 if (!DAT_004dc404) {
 void* entries[3];
 void* mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CButtonCondition>)); entries[0]=0;
 if(mem) {
 fight::ParamEnumConstList<CButtonCondition>* p=new(mem) fight::ParamEnumConstList<CButtonCondition>("button");
 p->list=((unsigned*)&DAT_0049ee30); p->count=13; p->callback=(void (*)())FUN_00047ab0; entries[0]=p;
 }
 mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CButtonCondition>)); entries[1]=0;
 if(mem) {
 unsigned count=(*(unsigned*)&DAT_00427754);
 fight::ParamEnumConstList<CButtonCondition>* p=new(mem) fight::ParamEnumConstList<CButtonCondition>("compareTime");
 p->count=count; p->list=((char*)&DAT_0042773c); p->callback=(void (*)())FUN_00047ac0; entries[1]=p;
 }
 mem=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CButtonCondition>)); entries[2]=0;
 if(mem) {
 fight::ParamFloatConstRange<CButtonCondition>* p=new(mem) fight::ParamFloatConstRange<CButtonCondition>("time");
 p->callback=(void (*)())FUN_00047ad0; entries[2]=p;
 }
 FUN_002347b0(((unsigned*)&DAT_004dc400), entries,3);
 }
 ++DAT_004dc404;
}

} // namespace fn_f4b51f75
