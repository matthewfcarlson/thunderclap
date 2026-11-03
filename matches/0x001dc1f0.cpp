#include "gen/global.h"
#include "gen/owners.h"
struct CSPManager_nv_1dc1f0 {
    int FUN_001dc070(void*);
};
bool owners::Obj_1dc1f0::FUN_001dc1f0(void* param) {
    if (param) {
        int i = ((CSPManager_nv_1dc1f0*)(((CSPManager*)this)))->FUN_001dc070((char*)param + 8);
        if (i >= 0) {
            int x = values[i * 20];
            return ((unsigned char*)this)[(x + 0x104e) * 20] >> 1 & 1;
        }
    }
    return false;
}