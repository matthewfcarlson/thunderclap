#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

extern int* FindThing(int, int);
extern "C" int * __cdecl FUN_0021a3e0(void *, void *, void *);
int* Target(hulk_intptr param1, hulk_intptr param2, int param3) {
    int locals[2];
    int* p = FindThing(param2, param3);
    if (p == (int*)((hulk_intptr)((char*)&DAT_00426824))) {
        *(float*)&locals[1] = (float)param3;
        locals[0] = 3;
        return FUN_0021a3e0((void *)(hulk_uintptr)(int)param1, (void *)(hulk_uintptr)(int)param2, &locals[0]);
    }
    return p;
}
