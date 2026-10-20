#include "compat/ptr.h"
extern int WorldCollisionObjectLoader_vftable;
class WorldCollisionObjectLoader {
  public:
    virtual void Dummy();
    int a;
    int b;
    int c;
    int d;
    WorldCollisionObjectLoader();
};
WorldCollisionObjectLoader::WorldCollisionObjectLoader() {
    a = 0;
    b = 0x07010025;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = (hulk_intptr)&WorldCollisionObjectLoader_vftable;
}
