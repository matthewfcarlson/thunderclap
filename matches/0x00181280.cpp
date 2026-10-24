#include "gen/hulkfight.h"

class Helper_181280 {
  public:
    void Init();
};
extern char BallAndChainShootTrack_vftable;
class BallAndChainSpinTrack_181280 {
  public:
    void Finish();
};

void hulkfight::motion::BallAndChainShootTrack::FUN_00181280() {
    *(void**)this = &BallAndChainShootTrack_vftable;
    ((Helper_181280*)((char*)this + 0x78))->Init();
    ((Helper_181280*)((char*)this + 0x60))->Init();
    ((BallAndChainSpinTrack_181280*)this)->Finish();
}
