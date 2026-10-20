#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

extern int g_vftable_24d380;
namespace om { class EntityLoader {
  public:
    int vptr;
    EntityLoader* vfunc_2(unsigned char);
}; }
extern void FUN_00247550(void*, om::EntityLoader*);
om::EntityLoader* om::EntityLoader::vfunc_2(unsigned char param) {
    vptr = (hulk_intptr)&g_vftable_24d380;
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e62d8), this);
    return this;
}