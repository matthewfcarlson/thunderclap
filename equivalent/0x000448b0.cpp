// STATUS: equivalent (tools/equiv.py level 3: 2270 inputs, branch coverage 8/8)
// FUN_000448b0 @ 0x000448b0
#include "decls/data/game/hulkfight.h"

struct Entry { int first; int second; float value; int unused; };
struct Obj { char pad[0x480]; Entry entries[14]; int count; float FUN_000448b0(int first, int second); };
float Obj::FUN_000448b0(int first, int second) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return (*(float*)&DAT_003f3388);
}