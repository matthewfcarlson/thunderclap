#include "decls/data/engine/om.h"
// data: gCount_245270 = DAT_004e5f0c

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_00429158[];
namespace om {
class Entity {
  public:
    unsigned long* mVptr;
    Entity* vfunc_2(unsigned char);
};
} // namespace om
void FUN_00244b20(void*, om::Entity*);
void thunk_FUN_00267090(om::Entity*);
om::Entity* om::Entity::vfunc_2(unsigned char param) {
    void* p = (*(void**)&DAT_004cc08c);
    mVptr = (unsigned long*)((hulk_intptr)DAT_00429158);
    FUN_00244b20(p, this);
    --DAT_004e5f0c;
    mVptr = (unsigned long*)((hulk_intptr)DAT_003f6098);
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}