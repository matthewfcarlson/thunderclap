// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00155330 @ 0x00155330
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern void FUN_0014c4f0();
extern void FUN_0014c500();
extern void* __cdecl FUN_0008d690(unsigned int);
struct Base_155330 { void FUN_00234cc0(const char*); };
namespace hulkfight { namespace motion { class CollisionSourceTypeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 int count;
 void (*callback)();
 int tail;
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_00155330() {
 if (DAT_004e104c == 0) {
  Param* params[2];
  void* storage = FUN_0008d690(32);
  if (storage) {
   int count = (*(int*)&DAT_00427760);
   ((Base_155330*)storage)->FUN_00234cc0("compare");
   Param* p = new (storage) Param;
   p->count = count;
   p->values = ((char*)&DAT_00427758);
   p->callback = &FUN_0014c4f0;
   params[0] = p;
  } else params[0] = 0;
  storage = FUN_0008d690(32);
  if (storage) {
   ((Base_155330*)storage)->FUN_00234cc0("type");
   Param* p = new (storage) Param;
   p->values = ((char*)&DAT_004af9f0);
   p->count = 2;
   p->callback = &FUN_0014c500;
   params[1] = p;
  } else params[1] = 0;
  FUN_002347b0(&DAT_004e1048, params, 2);
 }
 ++DAT_004e104c;
}
