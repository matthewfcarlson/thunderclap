#include "compat/ptr.h"
extern "C" int __cdecl FUN_00344e74(void*, int, int, int, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitWaitTrack;
}
} // namespace hulkfight
extern int DAT_0049850c, DAT_004b3030;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004b3030, 0) != 0;
}