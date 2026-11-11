// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ff20..0x0014ffc0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HealthAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fba48206 {
#define TREE_TU_END }
namespace fn_fba48206 {} using namespace fn_fba48206;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fba48206 {
struct Stats_14ff20 {
    char pad0[0x1b0c];
    float offset;       // 0x1b0c
    void FUN_0003b1c0(float value, int flag);
};
struct Info_14ff20 {
    char pad0[0x10];
    float value;        // 0x10
    char negate;        // 0x14
    char useOffsetA;    // 0x15
    char useOffsetB;    // 0x16
};
extern "C" Stats_14ff20 *__fastcall FUN_00059a30(Owner *ctx);

} // namespace fn_fba48206

// 0x0014ff20 hulkfight::motion::HealthAction::vfunc_3 (149 B): equivalent/0x0014ff20.cpp
// sym: ?vfunc_3@HealthAction@motion@hulkfight@@UAE_NHH@Z @547a00eec289 @w931e8b585052
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// hulkfight::motion::HealthAction::vfunc_3 @ 0x0014ff20
bool hulkfight::motion::HealthAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if ((*(Owner * *)&this->f_20) == 0)
        return false;
    Stats_14ff20 *stats = FUN_00059a30(FUN_000592a0((*(Owner * *)&this->f_20)));
    if (stats == 0)
        return false;
    int flag = (*(Info_14ff20 * *)&this->f_1c)->negate != 0;
    if ((*(Info_14ff20 * *)&this->f_1c)->useOffsetB)
        stats->FUN_0003b1c0(stats->offset - (*(Info_14ff20 * *)&this->f_1c)->value, flag);
    else if ((*(Info_14ff20 * *)&this->f_1c)->useOffsetA)
        stats->FUN_0003b1c0((*(Info_14ff20 * *)&this->f_1c)->value + stats->offset, flag);
    else
        stats->FUN_0003b1c0((*(Info_14ff20 * *)&this->f_1c)->value, flag);
    return false;
}

