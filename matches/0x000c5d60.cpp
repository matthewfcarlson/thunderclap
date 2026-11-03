#include "gen/owners.h"
struct Obj_c5d60 {
};
extern "C" bool FUN_000c5d60(Obj_c5d60* obj, int index) {
    int local[41];
    for (int i = 0; i < 1; ++i) {
        Obj_c5d60* p = ((Obj_c5d60 *)((owners::C_af3a0 *)obj)->FUN_000af3a0(i));
        ((owners::C_af0f0 *)p)->FUN_000af0f0(local);
        if (local[index * 3] == 1)
            return true;
    }
    return false;
}