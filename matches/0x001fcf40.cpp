#include "compat/ptr.h"
class CTriggerVolumeManager_1fcf40 {
  public:
    char pad[0x20c];
    int count;
    void* buffer;
    hulk_intptr foo();
};
extern void __fastcall FUN_001fb970(void*);
hulk_intptr CTriggerVolumeManager_1fcf40::foo() {
    hulk_intptr result = 0;
    if (count < 256) {
        char* p = (char*)buffer + (count << 6);
        FUN_001fb970(p);
        ++count;
        result = (hulk_intptr)p;
    }
    return result;
}