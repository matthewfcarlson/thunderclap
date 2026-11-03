#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

struct Obj_48db0 {
    char _pad[0x2098];
    int f1;
    int f2;
};
struct Stage_48db0 {
    Obj_48db0* Get();
};
struct Lookup_48db0 {
};

bool CNameFlagCondition::vfunc_7(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    Obj_48db0* obj = ((Stage_48db0 *)((owners::Object_592a0 *)(((Lookup_48db0*)arg)))->FUN_000592a0())->Get();
    switch (this->f_0c) {
    case 1:
        return (this->f_10 != obj->f1 || this->f_14 != obj->f2);
    case 0:
        return (this->f_10 == obj->f1 && this->f_14 == obj->f2);
    }
    return false;
}
