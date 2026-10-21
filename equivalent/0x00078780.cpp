// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00078780 @ 0x00078780
#include "compat/ptr.h"
typedef unsigned int uint;
struct RandomState { uint first; uint second; hulk_freg FUN_00078780(); };
hulk_freg RandomState::FUN_00078780() {
    first = (first & 0xffff) * 0x9069 + (first >> 16);
    second = (second & 0xffff) * 0x4650 + (second >> 16);
    union { uint bits; float value; } result;
    result.bits = (((first << 16) + (second & 0xffff)) & 0x7fffff) | 0x3f800000;
    return result.value - 1.0f;
}