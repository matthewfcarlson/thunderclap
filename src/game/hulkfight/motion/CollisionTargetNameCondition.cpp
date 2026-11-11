// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e760..0x0014e810 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionTargetNameCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f4d474da {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4d474da {} using namespace fn_f4d474da;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4d474da {
extern "C" {
extern char DAT_00494b44;
}
extern "C" {
extern char DAT_00494b60;
}
extern "C" {
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
}
struct NameProvider_14e760 { unsigned __int64 FUN_000443c0(); };
struct NamedData { char pad[8]; unsigned low,high; };
struct Entity { char pad[0xec]; NamedData* name; char gap[0x2c]; NameProvider_14e760* provider; };
struct Collision_14e760 { char pad[8]; Entity* entity; unsigned type; };
struct State_14e760 { char pad[0x50]; Collision_14e760* collision; };
struct Input_14e760 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_14e760* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionTargetNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Input_14e760*,void*);
 char pad[8]; unsigned mode; unsigned low,high;
};
} }


// 0x0014e760 hulkfight::motion::CollisionTargetNameCondition::vfunc_6 (170 B): equivalent/0x0014e760.cpp
// sym: ?vfunc_6@CollisionTargetNameCondition@motion@hulkfight@fn_f4d474da@@UAE_NPAXPAUInput_14e760@4@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 30/30)
// hulkfight::motion::CollisionTargetNameCondition::vfunc_6 @ 0x0014e760
namespace hulkfight { namespace motion {
bool CollisionTargetNameCondition::vfunc_6(void*,Input_14e760* input,void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_14e760* state=input->slot3();
 if (!state || !state->collision) return false;
 Collision_14e760* collision=state->collision;
 unsigned valueLow=0, valueHigh=0;
 if (collision->type==5) { if (collision->entity && collision->entity->name) { valueLow=collision->entity->name->low; valueHigh=collision->entity->name->high; } }
 else if(collision->type==1) { if(collision->entity && collision->entity->provider) { unsigned __int64 value=collision->entity->provider->FUN_000443c0(); valueLow=(unsigned)value; valueHigh=(unsigned)(value>>32); } }
 if(mode==0) return valueLow==low && valueHigh==high;
 if(mode==1) return valueLow!=low || valueHigh!=high;
 return false;
}
} }

} // namespace fn_f4d474da
