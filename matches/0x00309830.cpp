#include "gen/owners.h"
class Obj_309830 {
  public:
    char pad[0x10];
    Obj_309830* target();
};
Obj_309830* Obj_309830::target() {
    ((owners::Obj_2fd730 *)this)->FUN_002fd730();
    return (Obj_309830*)((char*)this + 0x10);
}