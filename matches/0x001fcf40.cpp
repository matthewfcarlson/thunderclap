#include "gen/global.h"

#include "compat/ptr.h"
extern void __fastcall FUN_001fb970(void*);

hulk_intptr CTriggerVolumeManager::FUN_001fcf40() {
    hulk_intptr result = 0;
    if (this->f_20c < 256) {
        char* p = (char*)(*(void * *)&this->f_210) + (this->f_20c << 6);
        FUN_001fb970(p);
        ++this->f_20c;
        result = (hulk_intptr)p;
    }
    return result;
}
