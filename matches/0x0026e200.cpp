#include "compat/ptr.h"
class X_26e200 {
  public:
    char pad[0x1d4];
    int mHead;
    bool f(void*);
};
bool X_26e200::f(void* p) {
    hulk_intptr i = mHead;
    while (i != 0) {
        if (i == (hulk_intptr)p)
            return true;
        i = *(int*)(i + 0x10);
    }
    return false;
}