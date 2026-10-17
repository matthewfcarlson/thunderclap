// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00078780 @ 0x00078780
typedef unsigned int uint;
struct RandomState { uint first; uint second; float FUN_00078780(); };
float RandomState::FUN_00078780() {
    first = (first & 0xffff) * 0x9069 + (first >> 16);
    second = (second & 0xffff) * 0x4650 + (second >> 16);
    union { uint bits; float value; } result;
    result.bits = (((first << 16) + (second & 0xffff)) & 0x7fffff) | 0x3f800000;
    return result.value - 1.0f;
}