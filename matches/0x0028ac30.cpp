#include "gen/pure3d.h"

class pure3d__Channel {
  public:
    virtual ~pure3d__Channel();
    virtual void vfunc_1();
    virtual unsigned int GetTypeID();
};

class pure3d__SimpleChannel : public pure3d__Channel {};

unsigned int pure3d::BoolChannel::vfunc_2() {
    return 0x4c4f4f42;
}
