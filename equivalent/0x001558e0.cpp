// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001558e0 @ 0x001558e0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* __cdecl operator new(unsigned int, void* memory) { return memory; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void SetCompare_0014c640(); extern "C" void SetCharge_0014c660(); extern "C" void SetUseArmorValue_0014c680();
namespace hulkfight { namespace motion { class CollisionChargeCondition_1558e0; } }
struct BaseEnum_1558e0 { virtual void slot(); char pad[12]; const char* list; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
struct BaseFloat_1558e0 { virtual void slot(); char pad[12]; void (*callback)(); int tail;  };
struct BaseBool { virtual void slot(); char pad[12]; void (*callback)(); int tail;  };
namespace fight {
template<class T> struct ParamEnumConstList_1558e0 : BaseEnum_1558e0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange_1558e0 : BaseFloat_1558e0 { virtual void slot(); };
template<class T> struct ParamBool_1558e0 : BaseBool { virtual void slot(); };
}
typedef fight::ParamEnumConstList_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Enum_1558e0;
typedef fight::ParamFloatConstRange_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Float_1558e0;
typedef fight::ParamBool_1558e0<hulkfight::motion::CollisionChargeCondition_1558e0> Bool_1558e0;
extern "C" void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (!(*(int*)&DAT_004e10a4)) {
  void* objects[3];
  Enum_1558e0* p=(Enum_1558e0*)FUN_0008d690((int)sizeof(Enum_1558e0));
  if(p) { int count=(*(int*)&DAT_00427754); p->FUN_00234cc0("compare"); p->count=count; new(p) Enum_1558e0; p->list="lwB"; p->callback=SetCompare_0014c640; }
  objects[0]=p;
  Float_1558e0* f=(Float_1558e0*)FUN_0008d690((int)sizeof(Float_1558e0));
  if(f) { ((fight::ParamValueFloat *)(BaseFloat_1558e0 *)f)->FUN_00234960("charge"); new(f) Float_1558e0; f->callback=SetCharge_0014c660; } objects[1]=f;
  Bool_1558e0* b=(Bool_1558e0*)FUN_0008d690((int)sizeof(Bool_1558e0));
  if(b) { ((fight::ParamValueBool *)(BaseBool *)b)->FUN_00234860("useArmorValue"); new(b) Bool_1558e0; b->callback=SetUseArmorValue_0014c680; } objects[2]=b;
  FUN_002347b0(((int*)&DAT_004e10a0),objects,3);
 }
 ++(*(int*)&DAT_004e10a4);
}
