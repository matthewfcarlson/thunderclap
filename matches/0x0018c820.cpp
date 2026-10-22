// Same code shape as 0x0014c420 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"
void* __cdecl alloc(hulk_uintptr);
struct PropAnimationTrack_18c820 {
    void* init();
};
void* f() {
    hulkfight::motion::PropAnimationTrack* p = (hulkfight::motion::PropAnimationTrack*)alloc(0x30);
    if (p)
        return ((PropAnimationTrack_18c820*)(p))->init();
    return 0;
}