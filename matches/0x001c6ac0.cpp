#include "compat/ptr.h"
extern "C" unsigned char gFlagByte;
extern "C" unsigned int gFlagWord;
extern "C" unsigned char gBuffer_1c6ac0;
struct Obj_1c6ac0 {
    char pad[0x10];
    hulk_intptr value;
};
extern "C" void* __fastcall FUN_001c6ac0(Obj_1c6ac0* self, void*) {
    if (self->value)
        return (void*)(self->value + 0x14);
    unsigned char c = gFlagByte;
    unsigned int one = 1;
    if ((one & c) == 0)
        gFlagWord |= one;
    return &gBuffer_1c6ac0;
}