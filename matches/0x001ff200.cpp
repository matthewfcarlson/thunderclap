#include "compat/ptr.h"
class CTriggerVolumeManager_1ff200 {
  public:
    typedef unsigned char (CTriggerVolumeManager_1ff200::*Fn)(int, int, int, int);
};
void f(CTriggerVolumeManager_1ff200* obj, int* args, unsigned char* out, CTriggerVolumeManager_1ff200::Fn fn) {
    int* p = args;
    int a = *p++;
    int b = *p;
    int c = *++p;
    *(unsigned char*)&args = *(unsigned char*)(p + 1);
    unsigned char v = (obj->*fn)(a, b, c, (hulk_intptr)args);
    if (out)
        *out = v;
}