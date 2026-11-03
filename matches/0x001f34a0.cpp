#include "gen/owners.h"
extern int FindThing(int, int);
extern void DoThing(int, int, void*);


void owners::Owner_1f34a0::FUN_001f34a0(hulk_intptr param2, int param3) {
    int found = FindThing(value, ((int)param2));
    if (found != 0) {
        int local[2];
        local[1] = param3;
        local[0] = 0;
        DoThing(value, found, local);
    }
}