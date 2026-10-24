#include "gen/global.h"

class Item;
class Helper {
  public:
    void Apply(Item*, int);
};
class Mid {
    char pad[12];

  public:
    Helper* helper;
};
struct CTriggerVolumeManager_nv_1fcc80 {
    Item* Find(int);
};

void CTriggerVolumeManager::FUN_001fcc80(int a, int b) {
    Item* p = ((CTriggerVolumeManager_nv_1fcc80*)this)->Find(a);
    if (p)
        (*(Mid * *)&this->f_04)->helper->Apply(p, b);
}
