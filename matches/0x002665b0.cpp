// Same code shape as 0x00236820 (propagated; names are from that function)
#include "gen/owners.h"
class Obj_2665b0 {
  public:
    void A();
    void Target();
};
void Obj_2665b0::Target() {
    A();
    ((owners::C_231050 *)this)->FUN_00231050();
}