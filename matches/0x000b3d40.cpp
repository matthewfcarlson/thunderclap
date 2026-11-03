#include "gen/owners.h"
class B_b3d40 {
  public:
};
class A_b3d40 {
  public:
    int pad;
    B_b3d40* member;
    void target();
};
void A_b3d40::target() {
    ((owners::Obj_b3b50 *)member)->FUN_000b3b50(1);
}