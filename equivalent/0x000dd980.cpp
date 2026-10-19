// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 11/12, incomplete)
// ControllerPoller::vfunc_2 @ 0x000dd980
#include "gen/global.h"
#include "decls/data/game/global.h"

struct PollMapping {
    int button;
    int code;
};

void ControllerPoller::vfunc_2() {
    PollMapping* mappings = (PollMapping*)&DAT_004de800;
    int* count = (int*)&DAT_004de8c0;
    for (int button = 4; button <= 9 && *count < 24; ++button) {
        int code;
        switch (button) {
        case 4:
            code = 8;
            break;
        case 5:
            code = 10;
            break;
        case 6:
            code = 11;
            break;
        case 7:
            code = 9;
            break;
        case 8:
            code = 12;
            break;
        default:
            code = 13;
            break;
        }
        mappings[*count].button = button;
        mappings[*count].code = code;
        ++*count;
    }
}