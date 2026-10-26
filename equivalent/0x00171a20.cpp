// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PushOutAction::vfunc_3 @ 0x00171a20
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Table_171a20 { char pad[0xc]; unsigned int limit; unsigned int FUN_002843a0(unsigned int lo, unsigned int hi); };
struct Layers_171a20 { char pad[0x64]; Table_171a20 *table; };
struct Ctx_171a20 {
    void *FUN_00059a30();
    Layers_171a20 *FUN_00059a40();
};
struct Owner_171a20 { Ctx_171a20 *FUN_000592a0(); };
struct Data_171a20 { char pad[0x18]; unsigned int keyLo; unsigned int keyHi; };

bool hulkfight::motion::PushOutAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Ctx_171a20 *ctx = (*(Owner_171a20 * *)&this->f_20)->FUN_000592a0();
    if (ctx == 0)
        return false;
    if (ctx->FUN_00059a30() == 0)
        return false;
    Layers_171a20 *layers = ctx->FUN_00059a40();
    if (layers == 0)
        return false;
    Table_171a20 *t = layers->table;
    unsigned int lo = (*(Data_171a20 * *)&this->f_1c)->keyLo;
    unsigned int hi = (*(Data_171a20 * *)&this->f_1c)->keyHi;
    if ((lo | hi) != 0) {
        (*(unsigned int *)&this->f_24) = t->FUN_002843a0(lo, hi);
        if ((*(unsigned int *)&this->f_24) == 0xffff)
            (*(unsigned int *)&this->f_24) = 0;
    }
    return (*(unsigned int *)&this->f_24) < t->limit;
}
