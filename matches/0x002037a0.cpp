#include "gen/owners.h"
struct Item {
    char pad[0x54];
    short id;
};
struct List {
    char pad[0x18];
    int Count();
};
struct Holder {
    char pad[4];
    List* list;
};
extern "C" Holder* __cdecl FUN_001c3d90();
int owners::Obj_2037a0::FUN_002037a0() {
    Holder* h = FUN_001c3d90();
    List* list = h->list;
    int count = ((List*)((char*)list + 0x18))->Count();
    for (int i = 0; i < count; ++i) {
        Item* p = ((Item *)((owners::Thing_1c7f80 *)list)->FUN_001c7f80((unsigned int)i));
        int id = p->id;
        if (flags[id] == 2)
            return id;
    }
    return -1;
}