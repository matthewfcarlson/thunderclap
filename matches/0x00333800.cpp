#include "gen/owners.h"
class A_333800 {
  public:
    char pad[0x64];
    int m64;
    void Set(int arg);
};

void A_333800::Set(int arg) {
    m64 = arg;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}
