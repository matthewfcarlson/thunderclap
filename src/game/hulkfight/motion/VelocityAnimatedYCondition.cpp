// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00168280..0x00168380 (kind game, layer game, confidence medium), dominant class hulkfight::motion::VelocityAnimatedYCondition
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f563e818 {
#define TREE_TU_END }
namespace fn_f563e818 {} using namespace fn_f563e818;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f563e818 {
extern char DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_00018960(float,float,float);
struct C_168280 { float FUN_000356f0(); };
struct B_168280 { C_168280* FUN_00059a30(); };
struct A_168280 {  };

} // namespace fn_f563e818

// 0x00168280 hulkfight::motion::VelocityAnimatedYCondition::vfunc_6 (232 B): equivalent/0x00168280.cpp
// sym: ?vfunc_6@VelocityAnimatedYCondition@motion@hulkfight@@UAE_NPAX00@Z @a1df613b64c9 @wc10fb2e99946
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityAnimatedYCondition::vfunc_6 @ 0x00168280
bool hulkfight::motion::VelocityAnimatedYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { A_168280 * actor = (A_168280 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float value=((B_168280 *)((owners::Object_592a0 *)actor)->FUN_000592a0())->FUN_00059a30()->FUN_000356f0();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return FUN_00018960(value,this->f_10,0.00001f);
 case 3: return !FUN_00018960(value,this->f_10,0.00001f);
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 }
 return false;
}

