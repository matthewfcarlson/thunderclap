// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 0/0)
// FUN_002382a0 @ 0x002382a0
typedef unsigned int uint;
struct RandomState { uint low; uint high; };
extern RandomState* DAT_004e5acc;
extern const float DAT_003f32dc;
float FUN_002382a0()
{
    RandomState* state = DAT_004e5acc;
    uint a = state->low;
    state->low = (a & 0xffff) * 0x9069 + (a >> 16);
    uint b = state->high;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    state->high = b;
    union { uint bits; float value; } result;
    result.bits = (((state->low << 16) + (b & 0xffff)) & 0x7fffff) | 0x3f800000;
    return result.value - DAT_003f32dc;
}