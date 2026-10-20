#include "compat/ptr.h"
extern "C" int __cdecl FUN_0027f250();
class C_1f6cb0 {
  public:
    void FUN_00283340();
};
void __cdecl FUN_001f6cb0() {
    hulk_intptr value = FUN_0027f250();
    if (value != 0)
        ((C_1f6cb0*)value)->FUN_00283340();
}