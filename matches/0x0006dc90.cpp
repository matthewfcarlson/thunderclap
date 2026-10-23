#include "compat/ptr.h"
class CGrappleSoundTrack;
extern "C" int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
extern int DAT_0049850c, DAT_00499910;
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00499910, 0) != 0;
}