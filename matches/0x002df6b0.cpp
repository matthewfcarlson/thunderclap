// Same code shape as 0x002df690 (propagated; names are from that function)
#include "gen/pure3d.h"

class Obj_2df6b0 {
  public:
    void FUN(int, int, int);
};

void pure3d::PrimGroupStreamed::vfunc_11(int a) {
    (*(Obj_2df6b0 * *)&this->f_5c)->FUN(a, 0, 0);
}
