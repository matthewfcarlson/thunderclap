#include "gen/owners.h"
class Obj_333810 {
  public:
    char pad[0x68];
    int m68;
    void Set(int x);
};
void Obj_333810::Set(int x) {
    m68 = x;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}
