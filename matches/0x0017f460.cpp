#include "compat/ptr.h"
class Obj_17f460 {
  public:
    char pad[0x18];
    char* GetState_0017f460();
};
char* Obj_17f460::GetState_0017f460() {
    return (char*)((hulk_intptr)this + 0x18);
}