#include "decls/data/engine/unknown.h"
// data: count = DAT_0052a128, items = DAT_0052842c, lockdata = DAT_0052a0f0

struct Item_270a50 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
};
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
void FUN_00270a50() {
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    unsigned int i = 0;
    if ((unsigned int)(*(int*)&DAT_0052a128) > 0) {
        Item_270a50** p = ((Item_270a50**)&DAT_0052842c);
        do {
            Item_270a50* q = *p;
            if (q != 0) {
                q->A();
                FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
                q->D();
                q->B();
                FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
            }
            ++i;
            p += 0x47;
        } while (i < (unsigned int)(*(int*)&DAT_0052a128));
    }
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
}