#include "compat/ptr.h"
#include "gen/hulkfight.h"
void* __cdecl alloc(hulk_uintptr);
struct CivilianAnimationTrack_14c420 {
    void* init();
};
void* f() {
    hulkfight::motion::CivilianAnimationTrack* p = (hulkfight::motion::CivilianAnimationTrack*)alloc(0x30);
    if (p)
        return ((CivilianAnimationTrack_14c420*)(p))->init();
    return 0;
}