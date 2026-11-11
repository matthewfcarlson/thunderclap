// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ee00..0x0014ef10 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitWaitAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f66936df {
#define TREE_TU_END }
namespace fn_f66936df {} using namespace fn_f66936df;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f66936df {
class Helper_14ee00 {
  public:
    void* second();
};
class Helper_14ee30 {
  public:
    void* f59a30();
};
struct Helper2_14ee60 {
    void* run();
};
struct Helper1_14ee60 {
    Helper2_14ee60* run();
};
struct Stats_14ee80 {
    char pad00[0x58];
    float primary;           // 0x58
    float secondary;         // 0x5c
    char pad60[8];
    float tertiary;          // 0x68
};
struct Settings_14ee80 {
    char pad00[0x10];
    int mode;                // 0x10
};
struct Context {
    void FUN_00059a30();
};
class Entity {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Stats_14ee80 *GetStats();       // slot 3
};
class HitWaitAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Settings_14ee80 *settings;      // 0x1c
    Entity *entity;          // 0x20
    float elapsed;           // 0x24
};

} // namespace fn_f66936df

// 0x0014ee00 hulkfight::motion::InterruptAccumulatorSetAction::vfunc_3 (36 B): matches/0x0014ee00.cpp
// sym: ?vfunc_3@InterruptAccumulatorSetAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::InterruptAccumulatorSetAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    Helper_14ee00* h = (*(Helper_14ee00 * *)&this->f_20);
    void* a = ((void *)((owners::Object_592a0 *)h)->FUN_000592a0());
    void* b = ((Helper_14ee00*)a)->second();
    *(int*)((char*)b + 0x320) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    return false;
}


// 0x0014ee30 hulkfight::motion::InterruptPriorityAction::vfunc_3 (36 B): matches/0x0014ee30.cpp
// sym: ?vfunc_3@InterruptPriorityAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::InterruptPriorityAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    Helper_14ee30* h = (*(Helper_14ee30 * *)&this->f_20);
    Helper_14ee30* q = (Helper_14ee30*)((void *)((owners::Object_592a0 *)h)->FUN_000592a0());
    void* r = q->f59a30();
    *(int*)((char*)r + 0x31c) += *(int*)((char*)(*(Helper_14ee30 * *)&this->f_1c) + 0x14);
    return true;
}


// 0x0014ee60 hulkfight::motion::InterruptPriorityAction::vfunc_4 (32 B): matches/0x0014ee60.cpp
// sym: ?vfunc_4@InterruptPriorityAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::InterruptPriorityAction::vfunc_4() {
    Helper2_14ee60* a = (*(Helper1_14ee60 * *)&this->f_20)->run();
    int* b = (int*)a->run();
    *(int*)((char*)b + 0x31c) -= *(int*)((char*)(*(void * *)&this->f_1c) + 0x14);
}

namespace fn_f66936df {

// 0x0014ee80 hulkfight::motion::HitWaitAction::vfunc_5 (143 B): equivalent/0x0014ee80.cpp
// sym: ?vfunc_5@HitWaitAction@fn_f66936df@@UAE_NHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::HitWaitAction::vfunc_5 @ 0x0014ee80
bool HitWaitAction::vfunc_5(int a, float dt) {
    ((Context *)((owners::Object_592a0 *)entity)->FUN_000592a0())->FUN_00059a30();
    elapsed = dt + elapsed;
    float limit = 0.0f;
    Stats_14ee80 *stats = entity->GetStats();
    if (stats != 0) {
        switch (settings->mode) {
        case 0:
            limit = stats->primary;
            if (limit <= 0.0f)
                limit = stats->secondary;
            break;
        case 1:
            limit = stats->secondary;
            if (limit <= 0.0f)
                limit = stats->primary;
            break;
        case 2:
            limit = stats->tertiary;
            break;
        }
    }
    return !(limit <= elapsed);
}

} // namespace fn_f66936df
