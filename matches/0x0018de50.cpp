#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class VarAssignTrack_18de50 {};
} // namespace motion
} // namespace hulkfight
struct TypeRecord {
    void* vtable;
};
extern const TypeRecord varAssignType;
extern const TypeRecord baseTrackType;
extern "C" int __cdecl TrackCast(void*, int, const TypeRecord*, const TypeRecord*, int);
namespace fight {
class TrackFactoryCaster_18de50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::VarAssignTrack>::vfunc_0(void* __p0) { void * track = (void *)__p0;

    return TrackCast(track, 0, &baseTrackType, &varAssignType, 0) != 0;
}
