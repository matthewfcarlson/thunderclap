#include "gen/fight.h"

namespace fight {
class TrackFactory_187340 {
  public:
    virtual void dummy();
};
template <class T> class TrackFactoryTemplate_187340 : public TrackFactory_187340 {};
class TrackFactoryCaster_187340 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class ShieldArcTrack_187340;
} // namespace motion
} // namespace hulkfight
namespace fight {
} // namespace fight
// the original asks whether a factory is the ShieldArcTrack one: dynamic_cast from fight::TrackFactory (RTTI 0x0049850c)
// to fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack> (0x004be460)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return dynamic_cast<fight::TrackFactoryTemplate_187340<hulkfight::motion::ShieldArcTrack_187340>*>((fight::TrackFactory_187340*)p) != 0;
}
