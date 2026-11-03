#include "gen/owners.h"
class Helper_1f8a80 {
  public:
};
class Owner_1f8a80 {
  public:
    char pad[0x20];
    volatile int member;
    Helper_1f8a80* GetHelper();
    void Set(int);
};
void Owner_1f8a80::Set(int value) {
    Helper_1f8a80* h = GetHelper();
    ((owners::Obj_1d1900 *)h)->FUN_001d1900((hulk_intptr)member);
    member = value;
}