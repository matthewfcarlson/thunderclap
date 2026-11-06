#include "gen/fight.h"
extern char DAT_0049850c;
extern char DAT_004abd00;

int FUN_00344e74(void*, int, void*, void*, int);
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

    return (FUN_00344e74((void*)a, 0, (void*)&DAT_0049850c, (void*)&DAT_004abd00, 0) != 0);
}
