// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"


// 0x00128660 FUN_00128660 (274 B): equivalent/0x00128660.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?target@fn_f09e6d2d@@YAXXZ @975d8199eadb @w51ebbee36639
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f09e6d2d {} using namespace fn_f09e6d2d;
namespace fn_f09e6d2d {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_00128660 @ 0x00128660

extern void* __cdecl FUN_0008d690(unsigned);
extern void SetCompare_00123620();
extern void SetDistance_00123630();
extern void SetUseHulk_00123650();
extern void SetUseGroundPoint_00123670();

} // namespace fn_f09e6d2d
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f09e6d2d {

namespace hulkfight { namespace ai { class TargetDistanceCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const char* values;
 int count;
 void (*callback)();
 int remaining;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int remaining;
 void FUN_00234960(const char*);
};
template<class T> struct ParamBool {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int remaining;
 void FUN_00234860(const char*);
};
}
extern void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (DAT_004e0d80 == 0) {
 void* entries[4];
 typedef fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition> Enum;
 typedef fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition> Float;
 typedef fight::ParamBool<hulkfight::ai::TargetDistanceCondition> Bool;
 Enum* e=(Enum*)FUN_0008d690((int)sizeof(Enum));
 if(e) {
 int n=(*(int*)&DAT_00427754);
 e->FUN_00234cc0("compare");
 e->count=n;
 new(e) Enum;
 e->values="lwB";
 e->callback=SetCompare_00123620;
 }
 entries[0]=e;
 Float* f=(Float*)FUN_0008d690((int)sizeof(Float));
 if(f) {
 f->FUN_00234960("distance");
 new(f) Float;
 f->callback=SetDistance_00123630;
 }
 entries[1]=f;
 Bool* b=(Bool*)FUN_0008d690((int)sizeof(Bool));
 if(b) {
 b->FUN_00234860("useHulk");
 new(b) Bool;
 b->callback=SetUseHulk_00123650;
 }
 entries[2]=b;
 b=(Bool*)FUN_0008d690((int)sizeof(Bool));
 if(b) {
 b->FUN_00234860("useGroundPoint");
 new(b) Bool;
 b->callback=SetUseGroundPoint_00123670;
 }
 entries[3]=b;
 FUN_002347b0(&DAT_004e0d7c, entries, 4);
 }
 ++DAT_004e0d80;
}
} // namespace fn_f09e6d2d

