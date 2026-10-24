#include "gen/fight.h"

int FUN_00344e74(void*, int, void*, int, int);
namespace hulkfight {
namespace motion {
class HoverTrack_137760;
}
} // namespace hulkfight
struct TrackFactoryCaster_137760 {
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74((void*)a, 0, (void*)0x49850c, 0x4abd00, 0) != 0);
}
