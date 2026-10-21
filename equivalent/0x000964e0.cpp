// STATUS: equivalent (tools/equiv.py level 3: 19809 inputs, branch coverage 0/0)
// FUN_000964e0 @ 0x000964e0
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "compat/ptr.h"

typedef unsigned int uint;
struct RandomState { uint first; uint second; };
hulk_freg FUN_000964e0()
{
    RandomState *state = (*(RandomState**)&DAT_004e5acc);
    uint first = state->first;
    state->first = (first & 0xffff) * 0x9069 + (first >> 16);
    uint second = state->second;
    state->second = (second & 0xffff) * 0x4650 + (second >> 16);
    uint bits = ((state->second & 0xffff) + (state->first << 16)) & 0x7fffff;
    bits |= 0x3f800000;
    return *(float *)&bits - (*(float*)&DAT_003f32dc);
}