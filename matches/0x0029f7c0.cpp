#include "decls/data/engine/unknown.h"

#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" int __cdecl FUN_0008d690(int);
struct CacheManager_nv_29f7c0 {
    int Init(int, int);
};
void FUN_0029f7c0() {
    if ((*(int*)&DAT_0052cba0) == 0) {
        hulk_intptr x = FUN_0008d690(0x3c);
        if (x != 0)
            (*(int*)&DAT_0052cba0) = ((CacheManager_nv_29f7c0*)(((pure3d::LightsChooser::CacheManager*)(((pure3d::LightsChooser::CacheManager*)x)))))->Init(4, 0x100);
        else
            (*(int*)&DAT_0052cba0) = 0;
    }
}