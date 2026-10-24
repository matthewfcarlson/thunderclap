// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001dc100 @ 0x001dc100
#include "gen/global.h"

struct CSPManager_nv_1dc100 {
    int FUN_001dbfe0(int key);
};

char CSPManager::FUN_001dc100(int key, bool set) {
    int idx = ((CSPManager_nv_1dc100*)this)->FUN_001dbfe0(key);
    if (idx < 0)
        return 0;
    char* base = (char*)this;
    int link = *(short*)(base + idx * 40 + 0x62a);
    unsigned char* flags = (unsigned char*)(base + (link + 0x104e) * 20);
    if (set)
        *flags |= 2;
    else
        *flags &= 0xfd;
    return 1;
}
