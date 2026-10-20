#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
};
class CGrappleUninterruptibleTrack_76b40 : public BaseTrack {
  public:
    CGrappleUninterruptibleTrack_76b40() throw() : BaseTrack() {}
    virtual void v0();
    char padding[0x14];
};

template <> void* fight::TrackFactoryTemplate<CGrappleUninterruptibleTrack>::vfunc_5() {
    return (void*)(new CGrappleUninterruptibleTrack_76b40);
}
