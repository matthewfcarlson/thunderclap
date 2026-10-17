// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 0/0)
// FUN_000964e0 @ 0x000964e0
typedef unsigned int uint;
struct RandomState { uint first; uint second; };
extern RandomState *DAT_004e5acc;
extern float DAT_003f32dc;
float FUN_000964e0()
{
    RandomState *state = DAT_004e5acc;
    uint first = state->first;
    state->first = (first & 0xffff) * 0x9069 + (first >> 16);
    uint second = state->second;
    state->second = (second & 0xffff) * 0x4650 + (second >> 16);
    uint bits = ((state->second & 0xffff) + (state->first << 16)) & 0x7fffff;
    bits |= 0x3f800000;
    return *(float *)&bits - DAT_003f32dc;
}