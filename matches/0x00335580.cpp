#include "compat/ptr.h"
#include "gen/owners.h"
class Item {
  public:
    char pad[8];
    int type;
};
class Store {
  public:
    char pad[0x44];
    int count;
};
class Obj {
  public:
    char pad[4];
    Store* store;
    char** strings;
    bool length(int index, int* out);
};
bool Obj::length(int index, int* out) {
    if (index < 0)
        return false;
    if (index >= store->count)
        return false;
    if (((Item *)((owners::Thing_337090 *)store)->FUN_00337090(index))->type != 4)
        return false;
    const char* s = strings[index];
    if (!s) {
        *out = 0;
        return true;
    }
    const char* e = s + 1;
    char c;
    do {
        c = *s++;
    } while (c);
    *(hulk_intptr*)out = s - e;
    return true;
}