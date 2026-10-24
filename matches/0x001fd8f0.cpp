#include "gen/global.h"

struct CTriggerVolumeManager_nv_1fd8f0 {
    void* Find(__int64);
};
extern __int64 __cdecl Convert(void*);
class Other {
  public:
    unsigned char Valid();
};

unsigned char CTriggerVolumeManager::FUN_001fd8f0(void* p) {
    __int64 x = Convert(p);
    Other* o = (Other*)((CTriggerVolumeManager_nv_1fd8f0*)this)->Find(x);
    if (!o)
        return 0;
    return o->Valid();
}
