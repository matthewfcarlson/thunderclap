#include "gen/owners.h"
extern "C" int FUN_0024afe0(int);
void owners::Obj_25d3f0::FUN_0025d3f0(int* out) {
    if (out) {
        int v = value;
        if (v != 0) {
            int r = FUN_0024afe0(v);
            if (r == 2 && !flag) {
                *out = value;
                value = 0;
                state = 5;
                return;
            }
        } else {
            *out = 0;
        }
    }
    state = 5;
}