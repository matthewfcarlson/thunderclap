// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000fb240 @ 0x000fb240
#include "decls/data/game/global.h"

struct Loader {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(void **caster, unsigned int low, unsigned int high);
};
extern char DAT_0040ced4[];
struct Inventory {
    int FUN_000fa4b0(void *item);
    void FUN_000faf80(int result);
    void FUN_000fb240(void *item);
};
// equiv-conv: FUN_0027b020 ecx stack
extern __int64 __cdecl FUN_0027b020(Inventory *self, void *item);
void Inventory::FUN_000fb240(void *item) {
    __int64 value = FUN_0027b020(this, item);
    void *caster = DAT_0040ced4;
    int result = (*(Loader**)&DAT_004dd9cc)->slot3(&caster, (unsigned int)value, (unsigned int)(value >> 32));
    if (!result) {
        result = FUN_000fa4b0(item);
        if (!result) return;
    }
    FUN_000faf80(result);
}