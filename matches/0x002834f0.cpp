// Same code shape as 0x001c5640 (propagated; names are from that function)
#include "gen/owners.h"
class EffectQueue_2834f0 {
  public:
    virtual void f();
    void Cleanup2();
    ~EffectQueue_2834f0();
    int mData;
};
EffectQueue_2834f0::~EffectQueue_2834f0() {
    ((owners::Owner_280160 *)this)->FUN_00280160();
    Cleanup2();
}