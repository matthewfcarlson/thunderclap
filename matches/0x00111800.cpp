#include "gen/fight.h"

int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
class TrackFactoryCaster_111800 {
  public:
    virtual bool vfunc_0(const char* s);
    virtual void vfunc_1();
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    int r = FUN_00344e74(s, 0, (const char*)0x49850c, (const char*)0x4a46a8, 0);
    return r != 0;
}
