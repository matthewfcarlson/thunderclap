#include "compat/ptr.h"
extern "C" void __cdecl helper(hulk_intptr, int, int);
class Obj_1d1900 {
  public:
    char pad[8];
    int field;
    bool f(int n);
};
bool Obj_1d1900::f(int n) {
    if (n < 1)
        return false;
    helper(field, 0xffffd8f0, n);
    return true;
}