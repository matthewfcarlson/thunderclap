#include "compat/ptr.h"
extern "C" void __cdecl FUN_00066980();
class H {
  public:
    void* lookup(unsigned int, unsigned int);
};
extern const float gZero_670e0;
class C_670e0 {
  public:
    char pad[0x2f4];
    float f(unsigned int);
};
float C_670e0::f(unsigned int x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup(((hulk_intptr)(void (__cdecl*)())&FUN_00066980), x);
    if (!p)
        return gZero_670e0;
    return *(float*)((char*)p + 0x18);
}