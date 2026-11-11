// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049b40..0x00049c80 (kind game, layer game, confidence medium), dominant class CPropActorStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff301b22 {
#define TREE_TU_END }
namespace fn_ff301b22 {} using namespace fn_ff301b22;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff301b22 {
extern int* gTable_49b60;
class CCondition_49b60 {
  public:
    virtual int vfunc_0(int);
};
struct Counter_49bb0 {
    char pad0[0x40];
    int value;      // 0x40
};
struct Stats_49bb0 {
    char pad0[0x128];
    Counter_49bb0 *counter;
};
Owner *__fastcall FUN_000592a0(Owner *owner);
extern "C" Stats_49bb0 *__fastcall FUN_00059a30(Owner *ctx);


// 0x00049b40 FUN_00049b40 (19 B): matches/0x00049b40.cpp
// sym: ?FUN_00049b40@fn_ff301b22@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049b40() {
    FUN_00234810(((char*)&DAT_004dc4f0), ((char*)&DAT_004dc4f4));
}

} // namespace fn_ff301b22

// 0x00049b60 CPropActorStateCondition::vfunc_0 (16 B): matches/0x00049b60.cpp
// sym: ?vfunc_0@CPropActorStateCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CPropActorStateCondition::vfunc_0(int index) {
    int* p = gTable_49b60;
    return p[index];
}


// 0x00049bb0 CPropActorStateCondition::vfunc_7 (149 B): equivalent/0x00049bb0.cpp
// sym: ?vfunc_7@CPropActorStateCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// CPropActorStateCondition::vfunc_7 @ 0x00049bb0
bool CPropActorStateCondition::vfunc_7(void* __p0) { Owner * owner = (Owner *)__p0;

    Stats_49bb0 *stats = FUN_00059a30(FUN_000592a0(owner));
    if (stats->counter == 0)
        return false;
    int value = stats->counter->value;
    switch ((*(unsigned int *)&this->f_0c)) {
    case 0: return value < this->f_10;
    case 1: return value <= this->f_10;
    case 2: return value == this->f_10;
    case 3: return value != this->f_10;
    case 4: return value >= this->f_10;
    case 5: return value > this->f_10;
    }
    return false;
}

