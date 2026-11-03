#include "compat/ptr.h"
#include "gen/owners.h"
struct Sub {
};
struct Item {
    char pad[0x1d70];
    Sub sub;
};
struct Obj {
    Item* Find(unsigned int, unsigned int);
    void Func(int, int);
};
extern "C" unsigned __int64 __cdecl Query(int, int, hulk_intptr);
void Obj::Func(int id, int value) {
    unsigned __int64 x = Query(id, 0, 0);
    Item* p = Find((unsigned int)x, (unsigned int)(x >> 32));
    if (p)
        ((owners::Target_27b040 *)&(p->sub))->FUN_0027b040((hulk_uintptr)value);
}