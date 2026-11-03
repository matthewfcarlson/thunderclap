#include "gen/owners.h"
struct Item {
    char pad[8];
    int state;
};
struct List {
    char pad[0x44];
    int count;
};
struct Obj {
    void* v;
    List* list;
    unsigned char* flags;
    char get(int index, unsigned char* out);
};
char Obj::get(int index, unsigned char* out) {
    if (index < 0)
        return 0;
    if (index >= list->count)
        return 0;
    Item* p = ((Item *)((owners::Thing_337090 *)list)->FUN_00337090(index));
    if (p->state)
        return 0;
    *out = flags[index * 4];
    return 1;
}