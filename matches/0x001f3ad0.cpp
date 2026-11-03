#include "gen/owners.h"
struct Child_1f3ad0 {
    char pad[8];
    int value;
};
struct Obj_1f3ad0 {
    char pad[0xc8];
    Child_1f3ad0* child;
    bool run();
};
bool Obj_1f3ad0::run() {
    if (child && child->value) {
        ((owners::Obj_1f3400 *)child)->FUN_001f3400(0);
        return true;
    }
    return false;
}