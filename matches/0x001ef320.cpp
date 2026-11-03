#include "gen/owners.h"
owners::Obj_1ef320* owners::Obj_1ef320::FUN_001ef320() {
    owners::Obj_1ef320* p = this;
    for (int i = 0; i < 8; ++i) {
        p->Init();
        p = (owners::Obj_1ef320*)((char*)p + 8);
    }
    field = 0;
    return this;
}