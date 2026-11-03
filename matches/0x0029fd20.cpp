#include "decls/data/engine/unknown.h"
// data: gObject_29fd20 = DAT_0052cba0
#include "gen/owners.h"

struct Obj_29fd20 {
    void Method(int v, void* self);
};
void owners::Caller_29fd20::FUN_0029fd20(hulk_intptr value) {
    (*(Obj_29fd20**)&DAT_0052cba0)->Method(((int)value), this);
}
