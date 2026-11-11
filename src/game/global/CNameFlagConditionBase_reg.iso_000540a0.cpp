// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x000540a0 FUN_000540a0 (190 B): equivalent/0x000540a0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_f5fee164@@YAXXZ @b47b2ce67a23 @w8240b563afbe
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace fn_f5fee164 {} using namespace fn_f5fee164;
namespace fn_f5fee164 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000540a0 @ 0x000540a0


} // namespace fn_f5fee164
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f5fee164 {

void SetCompare_00048060();
void SetMotionHit_00048070();
void* __cdecl FUN_0008d690(unsigned int);
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const void* values;
 int count;
 void (*callback)();
 int trailing;
 void FUN_00234cc0(const char*);
};
}
class CMotionHitCondition;
typedef fight::ParamEnumConstList<CMotionHitCondition> Entry_540a0;
void __cdecl FUN_002347b0(void*,Entry_540a0**,int);
void __cdecl target() {
 if (DAT_004dc52c == 0) {
  Entry_540a0* entries[2];
  Entry_540a0* p = (Entry_540a0*)FUN_0008d690((int)sizeof(Entry_540a0));
  if (p) {
   int n = (*(int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Entry_540a0;
   p->count=n;
   p->values=((char*)&DAT_00427758);
   p->callback=SetCompare_00048060;
  }
  entries[0]=p;
  p=(Entry_540a0*)FUN_0008d690((int)sizeof(Entry_540a0));
  if (p) {
   p->FUN_00234cc0("motionHit");
   new (p) Entry_540a0;
   p->values=((char*)&DAT_0048f9c0);
   p->count=5;
   p->callback=SetMotionHit_00048070;
  }
  entries[1]=p;
  FUN_002347b0(&DAT_004dc528,entries,2);
 }
 ++DAT_004dc52c;
}
} // namespace fn_f5fee164

