#include "compat/ptr.h"
typedef unsigned int uint_26d320;
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, uint_26d320);
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr, uint_26d320);
class MemoryTwoWayAllocator_26d320 {
  public:
    char p[24];
    hulk_uintptr a, b, c, d, flag;
    hulk_uintptr f(uint_26d320 x, uint_26d320 y);
};
hulk_uintptr MemoryTwoWayAllocator_26d320::f(uint_26d320 x, uint_26d320 y) {
    hulk_uintptr r;
    if (flag == 0) {
        r = FUN_0026fd50(a, y);
        if (r + x < b) {
            a = r + x;
            ++c;
            return r;
        }
    } else {
        r = FUN_0026fd80(b - x, y);
        if (r > a) {
            b = r;
            ++d;
            return r;
        }
    }
    return 0;
}