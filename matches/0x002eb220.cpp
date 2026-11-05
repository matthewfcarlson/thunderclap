#include "compat/ptr.h"
typedef unsigned int uint_2eb220;
struct Thing_2eb220 {
    char pad[8];
    uint_2eb220 flags;
    char pad2[0x70];
    uint_2eb220 value;
};
void FUN_002eb220(hulk_intptr handle, Thing_2eb220* object, hulk_uintptr newValue) {
    if (handle && object) {
        object->value = newValue;
        object->flags |= 0x40;
    }
}