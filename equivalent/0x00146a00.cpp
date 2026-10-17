// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00146a00 @ 0x00146a00
#include "decls/data/game/unknown.h"

struct Angles {
    char pad[0x1c];
    float x, y, z;
    unsigned int FUN_00146a00(const float *input);
};
unsigned int Angles::FUN_00146a00(const float *input) {
    x = input[0] * (*(float*)&DAT_003f32b8);
    y = input[1] * (*(float*)&DAT_003f32b8);
    z = input[2] * (*(float*)&DAT_003f32b8);
    return (*reinterpret_cast<unsigned int *>(&z) & 0xffffff00u) | 1u;
}