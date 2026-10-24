#include "gen/global.h"

struct Item {
    void SetAngle(float);
};
struct CTriggerVolumeManager_nv_1fd8b0 {
    Item* Find(int, int);
};
struct Pair {
    int a, b;
};
Pair __cdecl Lookup(int);

bool CTriggerVolumeManager::FUN_001fd8b0(int key, float angle) {
    Pair p = Lookup(key);
    Item* item = ((CTriggerVolumeManager_nv_1fd8b0*)this)->Find(p.a, p.b);
    if (!item)
        return false;
    item->SetAngle(angle * 0.017453292519943295f);
    return true;
}
