// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00155af0 @ 0x00155af0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0014c710();
extern "C" void __cdecl FUN_0014c720();
struct ParamBase_155af0 {
 virtual void slot0();
 char pad[12];
 void* values;
 unsigned int count;
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
};
namespace hulkfight { namespace motion { class CollisionTargetTypeCondition; } }
namespace fight { template<class T> struct ParamEnumConstList : ParamBase_155af0 { virtual void slot0(); }; }
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Param**, int);
void FUN_00155af0() {
 if (!DAT_004e10bc) {
  Param* list[2];
  Param* p = (Param*)FUN_0008d690(32);
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   p->count = count;
   new (p) Param;
   p->values = ((unsigned int*)&DAT_00427758);
   p->callback = FUN_0014c710;
  }
  list[0] = p;
  p = (Param*)FUN_0008d690(32);
  if (p) {
   p->FUN_00234cc0("type");
   new (p) Param;
   p->values = ((unsigned int*)&DAT_004af9f0);
   p->count = 2;
   p->callback = FUN_0014c720;
  }
  list[1] = p;
  FUN_002347b0(&DAT_004e10b8, list, 2);
 }
 ++DAT_004e10bc;
}
