#include "gen/owners.h"
class Body_333820 {
  public:
    char pad[0x70];
    int mX;
    void SetX(int v);
};

void Body_333820::SetX(int v) {
    mX = v;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}
