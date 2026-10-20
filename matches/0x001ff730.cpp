#include "compat/ptr.h"
#include "gen/global.h"

void* CTriggerVolumeManager::vfunc_3(void* __p0) { hulk_intptr x = (hulk_intptr)__p0;

    return (void*)((char*)(x ? "Volume" : "Locator"));
}
