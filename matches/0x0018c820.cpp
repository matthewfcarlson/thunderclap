// Same code shape as 0x0014c420 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct PropAnimationTrack_nv_18c820 {
    void* init();
};
void* f() {
    hulkfight::motion::PropAnimationTrack* p = (hulkfight::motion::PropAnimationTrack*)FUN_0008d690((int)sizeof(hulkfight::motion::PropAnimationTrack));
    if (p)
        return ((PropAnimationTrack_nv_18c820*)(((hulkfight::motion::PropAnimationTrack*)(p))))->init();
    return 0;
}