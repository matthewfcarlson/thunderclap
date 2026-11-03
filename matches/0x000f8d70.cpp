#include "gen/owners.h"
extern int a;
extern int b;
struct This_first {
};
extern int __cdecl second(int, int, int*, int*, int);
hulk_intptr owners::Obj_f8d70::FUN_000f8d70(hulk_intptr x) {
    return second(((owners::Table_f8cc0 *)(((This_first*)this)))->FUN_000f8cc0((const char *)(hulk_uintptr)(int)(((int)x))), 0, &a, &b, 0);
}
