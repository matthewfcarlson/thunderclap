#include "gen/owners.h"
class Obj_201bd0 {
  public:
    char pad[0x20];
    void Target(int);
};
void Obj_201bd0::Target(int a0) {
    char* p = (char*)this;
    p += 0x20;
    ((owners::Target_27b040 *)(((Obj_201bd0*)p)))->FUN_0027b040((hulk_uintptr)a0);
}
