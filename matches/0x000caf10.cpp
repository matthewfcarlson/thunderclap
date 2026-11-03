#include "gen/owners.h"
class SubObj_caf10 {
  public:
};

class Obj_caf10 {
  public:
    char mPad[0x88];
    SubObj_caf10* mThing;
    void Target(int arg);
};

void Obj_caf10::Target(int arg) {
    if (mThing)
        ((owners::C_c7ae0 *)mThing)->FUN_000c7ae0(arg);
}
