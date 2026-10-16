#include "gen/global.h"

class FEObject_e39b0 {
  public:
    char pad[0x118];
};

int MapThing::vfunc_12() {
    return *(int*)((char*)this + 0x118);
}
