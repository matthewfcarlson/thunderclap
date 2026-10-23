#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int extra, a;
    BaseTrack() throw();
};
class Track_17e1e0 : public BaseTrack {
  public:
    int b;
    float c;
    int d, e, f, g;
    Track_17e1e0() throw() : b(0), d(0), e(0), f(0), g(0) {}
};
class SuckTrack_17e1e0 : public Track_17e1e0 {
  public:
    SuckTrack_17e1e0() throw() : Track_17e1e0() {
        c = -1.0f;
        a = 1;
    }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SuckTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::SuckTrack_17e1e0);
}
