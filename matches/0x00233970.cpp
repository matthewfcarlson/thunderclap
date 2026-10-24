#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_00427898[];
class Branch_233970 {
  public:
    void init();
    void finish();
};

void fight::Branch::FUN_00233970() {
    *(void**)this = (void*)((hulk_intptr)DAT_00427898);
    fight::Branch::vfunc_7();
    ((Branch_233970*)((char*)this + 0x18))->init();
    ((Branch_233970*)this)->finish();
}
