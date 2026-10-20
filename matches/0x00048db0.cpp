#include "compat/ptr.h"
#include "gen/global.h"

struct Obj_48db0 {
    char _pad[0x2098];
    int f1;
    int f2;
};
struct Stage_48db0 {
    Obj_48db0* Get();
};
struct Lookup_48db0 {
    Stage_48db0* Resolve();
};

bool CNameFlagCondition::vfunc_7(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    Obj_48db0* obj = ((Lookup_48db0*)arg)->Resolve()->Get();
    switch (this->f_0c) {
    case 1:
        return (this->f_10 != obj->f1 || this->f_14 != obj->f2);
    case 0:
        return (this->f_10 == obj->f1 && this->f_14 == obj->f2);
    }
    return false;
}
