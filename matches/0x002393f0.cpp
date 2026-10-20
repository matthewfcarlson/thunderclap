#include "compat/ptr.h"
class C_2393f0 {
  public:
    char pad[0x24];
    char* Get();
};

char* C_2393f0::Get() {
    return (char*)((hulk_intptr)this + 0x24);
}
