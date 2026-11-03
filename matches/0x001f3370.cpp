#include "gen/owners.h"
extern int __cdecl Find(int, int);
extern void __cdecl Act(int, int, int, int, int);
int owners::Obj_1f3370::FUN_001f3370(hulk_intptr arg) {
    int p = member;
    if (p == 0)
        return 0;
    int found = Find(p, ((int)arg));
    if (found == 0)
        return 0;
    Act(member, found, 1, 0, 0);
    return 1;
}