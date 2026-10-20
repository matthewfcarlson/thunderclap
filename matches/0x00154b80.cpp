#include "compat/ptr.h"
extern "C" int __cdecl check(void*, int, int, int, int);
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
extern int a, b;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_0(void* p) {
    return check(p, 0, (hulk_intptr)&a, (hulk_intptr)&b, 0) != 0;
}