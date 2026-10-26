#include "decls/data/game/global.h"
// data: gFlag_1cb7c0 = DAT_004c54a0

struct Slot_1cb7c0 {
    bool InUse();
    char pad[0x28];
};
struct Obj_1cb7c0 {
    void Set(Slot_1cb7c0* s, int v, int z);
};
class T_1cb7c0 {
  public:
    char pad[0x24];
    Slot_1cb7c0 mSlots[0x18];
    unsigned Find() {
        for (unsigned i = 0; i < 0x18; i++)
            if (!mSlots[i].InUse())
                return i;
        return 0xffffffff;
    }
    unsigned Alloc(Obj_1cb7c0* o, int v);
};
unsigned T_1cb7c0::Alloc(Obj_1cb7c0* o, int v) {
    if (!o)
        return 0xffffffff;
    unsigned i = Find();
    if (i == 0xffffffff)
        return i;
    (*(char*)&DAT_004c54a0) = 1;
    o->Set(&mSlots[i], v, 0);
    return i;
}
