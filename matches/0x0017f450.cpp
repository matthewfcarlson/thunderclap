#include "compat/ptr.h"
class Obj_17f450 {
  public:
    char pad[0x10];
    hulk_intptr m10;
    bool SetCompare_0017f450(void* p);
};

bool Obj_17f450::SetCompare_0017f450(void* p) {
    m10 = (hulk_intptr)p;
    return true;
}