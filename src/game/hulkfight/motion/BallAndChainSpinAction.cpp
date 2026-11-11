// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00182490..0x001825f0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::BallAndChainSpinAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f86d6f14 {
#define TREE_TU_END }
namespace fn_f86d6f14 {} using namespace fn_f86d6f14;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f86d6f14 {
struct Helper_182490 {
    char* second_00059a30();
};
struct Helper_1824c0 {
    void* Fng_00059a30();
};

} // namespace fn_f86d6f14

// 0x00182490 hulkfight::motion::PropThrowAction::vfunc_3 (36 B): matches/0x00182490.cpp
// sym: ?vfunc_3@PropThrowAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropThrowAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(Helper_182490 * *)&this->f_20))
        return false;
    Helper_182490* p = ((Helper_182490 *)((owners::Object_592a0 *)((*(Helper_182490 * *)&this->f_20)))->FUN_000592a0());
    *(p->second_00059a30() + 0x1f51) = 1;
    return true;
}


// 0x001824c0 hulkfight::motion::ShieldArcAction::vfunc_3 (40 B): matches/0x001824c0.cpp
// sym: ?vfunc_3@ShieldArcAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::ShieldArcAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if ((*(Helper_1824c0 * *)&this->f_20)) {
        void* a = ((void *)((owners::Object_592a0 *)((*(Helper_1824c0 * *)&this->f_20)))->FUN_000592a0());
        void* b = ((Helper_1824c0*)a)->Fng_00059a30();
        *(int*)((char*)b + 0x628) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    }
    return false;
}


// 0x001824f0 hulkfight::motion::BallAndChainSpinAction::vfunc_5 (251 B): equivalent/0x001824f0.cpp [wrapped: conflict: hulkfight::motion::BallAndChainSpinAction]
// sym: ?vfunc_5@BallAndChainSpinAction@motion@hulkfight@fn_001824f0@@UAE_NHM@Z
namespace fn_001824f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::BallAndChainSpinAction::vfunc_5 @ 0x001824f0
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022bc20(float,float,float); void FUN_0022ba70(float); void FUN_0022ca90(Matrix*,Matrix*); };
struct Item;
struct Manager_1824f0 { Item* FUN_00035ef0(unsigned); void FUN_0003acf0(unsigned,Item*,int,int,int,Matrix*); };
struct Owner_1824f0 { Manager_1824f0* FUN_00059a30(); };
struct Source_1824f0 { Owner_1824f0* FUN_000592a0(); };
struct Config_1824f0 { char pad[0x14]; unsigned id; float height; float offset; char pad2[4]; float speed; float x,y,z; };
namespace hulkfight { namespace motion { struct BallAndChainSpinAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float); char pad[0x18]; Config_1824f0* config; Source_1824f0* source; float angle; }; bool BallAndChainSpinAction::vfunc_5(int state,float dt) { if(state==1) { if(!source) return false; angle=angle+dt*config->speed; Owner_1824f0* owner=source->FUN_000592a0(); Manager_1824f0* manager=owner->FUN_00059a30(); unsigned id=config->id; Item* item=manager->FUN_00035ef0(id); if(item) { Matrix translation; translation.FUN_0022b980(); translation.FUN_0022bc20(config->x,config->y,config->z); translation.m[13]=config->offset; translation.m[14]=-config->height; Matrix rotation; rotation.FUN_0022b980(); rotation.FUN_0022ba70(angle); Matrix result; result.FUN_0022b980(); result.FUN_0022ca90(&translation,&rotation); manager->FUN_0003acf0(id,item,0,0,0,&result); } } return true; } } }
} // namespace fn_001824f0

