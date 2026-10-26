#include "decls/data/game/unknown.h"

struct Item {
    __int64 FUN_000443c0();
};
struct Object {
    char padding[0x11c];
    Item* item;
    bool FUN_00035ab0();
};
bool Object::FUN_00035ab0() {
    Item* p = item;
    if (!p)
        return false;
    __int64 value = p->FUN_000443c0();
    return value == (*(__int64*)&DAT_004dc0e0);
}