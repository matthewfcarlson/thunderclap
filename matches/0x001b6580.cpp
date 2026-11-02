#include "decls/data/game/global.h"
// data: gThing = DAT_004e2158

typedef unsigned int size_t;
void* operator new(size_t) throw();
class CCollisionManager_1b6580 {
  public:
    CCollisionManager_1b6580() throw();
    virtual void Init() throw();
    char pad[0x5a8];
};
extern "C" void * FUN_001b6580() {
    if (!(*(CCollisionManager_1b6580**)&DAT_004e2158)) {
        (*(CCollisionManager_1b6580**)&DAT_004e2158) = new CCollisionManager_1b6580;
        (*(CCollisionManager_1b6580**)&DAT_004e2158)->Init();
        return (CCollisionManager_1b6580 *)((*(CCollisionManager_1b6580**)&DAT_004e2158));
    }
    return (CCollisionManager_1b6580 *)((*(CCollisionManager_1b6580**)&DAT_004e2158));
}
