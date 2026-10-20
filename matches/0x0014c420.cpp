#include "gen/hulkfight.h"
void* __cdecl alloc(unsigned int);
struct CivilianAnimationTrack_nv_14c420 {
    void* init();
};
void* f() {
    hulkfight::motion::CivilianAnimationTrack* p = (hulkfight::motion::CivilianAnimationTrack*)alloc(0x30);
    if (p)
        return ((CivilianAnimationTrack_nv_14c420*)(p))->init();
    return 0;
}