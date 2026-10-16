#include "decls/data/engine/unknown.h"

extern int* FindThing(int, int);
extern void UseThing(int, int, void*);
void Target(int param1, int param2, int param3) {
    int locals[2];
    int* p = FindThing(param2, param3);
    if (p == (int*)((int)((char*)&DAT_00426824))) {
        *(float*)&locals[1] = (float)param3;
        locals[0] = 3;
        UseThing(param1, param2, &locals[0]);
    }
}
