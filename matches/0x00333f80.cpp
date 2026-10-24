// Same code shape as 0x0026d270 (propagated; names are from that function)
#include "gen/movie.h"

class IB_333f80 {
  public:
    void helper();
};
class PlayerBink_333f80 : public movie::Player2, public IB_333f80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void PlayerBink_333f80::vfunc_1() {
    IB_333f80::helper();
}
