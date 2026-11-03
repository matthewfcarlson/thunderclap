// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00024230 @ 0x00024230
#include "gen/owners.h"
struct Lookup {  };
struct Finder { struct Data { char pad[0x44]; Lookup* lookup; }; Data* data; char pad[8]; int count; int entries[1]; int FUN_00024230(int wanted); };
int Finder::FUN_00024230(int wanted) {
    for (int i = 0; i < count; ++i) {
        int result = ((int)((owners::ThisWrap_00059c10 *)(data->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(entries[i])));
        if (result != 0 && result == wanted) return i;
    }
    return -1;
}