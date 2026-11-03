#include "decls/data/engine/global.h"
// data: fmt_27ab00 = DAT_0042c120
#include "gen/owners.h"

extern int Format(char*, const char*, float*, float*, float*);
bool owners::Obj_27ab00::FUN_0027ab00(hulk_intptr a, float* p) {
    if (Check(((int)a)))
        return Format((char*)((char*)this + 0xd38 + index * 0x60), DAT_0042c120, p, (float*)((char*)p + 4),
                      (float*)((char*)p + 8)) == 3;
    return false;
}