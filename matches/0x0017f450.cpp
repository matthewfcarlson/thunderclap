#include "compat/ptr.h"
class Obj_17f450 {
  public:
    char pad[0x10];
    int m10;
    bool Set(void* p);
};

bool Obj_17f450::Set(void* p) {
    m10 = (hulk_intptr)p;
    return true;
}