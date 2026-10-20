#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int count;
    int zero;
};
class ClearFightParamsHitRecordTrack_15a060 : public BaseTrack {
  public:
    ClearFightParamsHitRecordTrack_15a060() throw() {
        zero = 0;
        count = 1;
    }
    virtual void a();
    virtual void b();
    virtual void c();
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::ClearFightParamsHitRecordTrack_15a060);
}
