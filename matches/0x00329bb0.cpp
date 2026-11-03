#include "gen/owners.h"
extern int gFlags_329bb0;
extern int gValues_329bb0[128];
extern int gMore[128];
void owners::State_329bb0::FUN_00329bb0(unsigned int index) {
    if (index < 4) {
        if (first[index] != 1) {
            first[index] = 1;
            gFlags_329bb0 = gFlags_329bb0 | 0x800;
            gValues_329bb0[index * 32] = 1;
        }
        if (second[index] != 1) {
            second[index] = 1;
            int value = gFlags_329bb0;
            int current = first[index];
            gFlags_329bb0 = value | 0x800;
            gMore[index * 32] = current;
        }
    }
}