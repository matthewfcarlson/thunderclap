// Same code shape as 0x001c3830 (propagated; names are from that function)
#include "gen/owners.h"
class Inner_1eb4d0 {
  public:
};
class Outer_1eb4d0 {
  public:
    Inner_1eb4d0* p;
    void g();
};
void Outer_1eb4d0::g() {
    ((owners::Obj_1eef00 *)p)->FUN_001eef00();
}