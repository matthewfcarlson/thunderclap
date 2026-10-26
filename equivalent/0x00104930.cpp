// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// CPathGraphAgent::vfunc_3 @ 0x00104930
#include "compat/ptr.h"
#include "gen/global.h"

#include "decls/data/game/global.h"

struct PathState {
    char pad[0x68];
    unsigned char blocked;
    char pad69;
    unsigned char active;
    char pad6b;
    float value;
};

hulk_freg CPathGraphAgent::vfunc_3(hulk_intptr , int ) {
    PathState *s = (*(PathState * *)&this->f_58);
    if (!s->active && !(s->value < (*(float*)&DAT_003f5d00)) && !s->blocked)
        return (*(float*)&DAT_0040d510);
    (*(unsigned char *)&this->f_5d) = 0;
    (*(unsigned char *)&this->f_5c) = 0;
    return (*(float*)&DAT_003f32e0);
}
