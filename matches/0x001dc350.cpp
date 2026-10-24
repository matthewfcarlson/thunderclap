#include "gen/global.h"

#include "compat/ptr.h"
struct CSPManager_nv_1dc350 {
    int Find(char*);
};

int CSPManager::FUN_001dc350(char* s) {
    int result = -1;
    int idx = ((CSPManager_nv_1dc350*)this)->Find(s);
    if (idx >= 0 && s != 0 && *s != 0) {
        char* entry = (char*)this + 0x608 + idx * 0x28;
        short v = *(short*)(entry + 0x22);
        if ((*((unsigned char*)this + (v + 0x104e) * 0x14) & 1) != 0 && *(int*)(entry + 0x18) != 0)
            result = *(int*)(*(hulk_intptr*)(entry + 0x18) + 0x40);
        else
            result = (int)*(signed char*)(entry + 0x26);
    }
    return result;
}
