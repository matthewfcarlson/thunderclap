#include "decls/data/engine/unknown.h"

extern int* FindThing(int, int);
extern int* UseThing(int, int, void*);
int* Target(int param1, int param2, int param3) {
    int locals[2];
    int* p = FindThing(param2, param3);
    if (p == (int*)((int)((char*)&DAT_00426824))) {
        *(float*)&locals[1] = (float)param3;
        locals[0] = 3;
        return UseThing(param1, param2, &locals[0]);
    }
    return p;
}
