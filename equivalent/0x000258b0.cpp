// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/8, incomplete)
// FUN_000258b0 @ 0x000258b0
#include "decls/data/game/unknown.h"

int __cdecl FUN_00096600(const char *a, const char *b);

class Palette_258b0 {
public:
    char pad0[0xd30];
    unsigned int colors[4];
    void FUN_000258b0(const char *name, float r, float g, float b);
};

void Palette_258b0::FUN_000258b0(const char *name, float r, float g, float b)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (FUN_00096600(name, ((const char**)&DAT_00496f8c)[i]) == 0)
            break;
    }
    if (i >= 4)
        return;
    unsigned int c = (int)r | 0xffffff00u;
    c <<= 8;
    c |= (int)g;
    c <<= 8;
    c |= (int)b;
    colors[i] = c;
}
