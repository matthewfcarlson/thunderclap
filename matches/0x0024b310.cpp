#include "compat/ptr.h"
class X_24b310 {
  public:
    char pad[0x78];
    unsigned char a, b, c;
    hulk_intptr f(void* p);
};
hulk_intptr X_24b310::f(void* p) {
    hulk_intptr i = ((char*)p - (char*)this) / 12;
    if (i == ((int)b + (int)a - 1) % (int)c)
        return 0;
    return (hulk_intptr)this + ((i + 1) % (unsigned int)c) * 12;
}