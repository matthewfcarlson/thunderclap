#include "compat/ptr.h"
typedef unsigned int uint;
struct Object {
    char pad[0x1bc9];
};
int __fastcall FUN_000bb670(Object* self) {
    return (hulk_intptr)((char*)self + 0x1bc9);
}