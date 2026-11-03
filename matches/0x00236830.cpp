// Same code shape as 0x00236820 (propagated; names are from that function)
#include "gen/owners.h"
class Obj_236830 {
  public:
    void A();
    void Target();
};
void Obj_236830::Target() {
    A();
    ((owners::C_231050 *)this)->FUN_00231050();
}