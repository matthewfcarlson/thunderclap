#include "decls/data/engine/unknown.h"
// data: count = DAT_0052a128, items = DAT_00528418 (records.h CoreDriveRegistryEntry), lockdata = DAT_0052a0f0

struct Item_270a50 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
};
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
extern "C" void FUN_00270a50() {
    FUN_0026d850(((char*)DAT_0052a0f0));
    unsigned int i = 0;
    if ((unsigned int)(*(int*)&DAT_0052a128) > 0) {
        CoreDriveRegistryEntry* p = DAT_00528418;
        do {
            Item_270a50* q = (Item_270a50*)p->drive;
            if (q != 0) {
                q->A();
                FUN_0026d840(((char*)DAT_0052a0f0));
                q->D();
                q->B();
                FUN_0026d850(((char*)DAT_0052a0f0));
            }
            ++i;
            ++p;
        } while (i < (unsigned int)(*(int*)&DAT_0052a128));
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}