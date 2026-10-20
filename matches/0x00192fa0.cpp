#include "compat/ptr.h"
class Obj_192fa0 {
  public:
    char pad[0x18];
    char* Get();
};

char* Obj_192fa0::Get() {
    return (char*)((hulk_intptr)this + 0x18);
}
