#include "compat/ptr.h"
#include "gen/owners.h"
class Item_280160 {
  public:
    virtual void A();
    virtual void Release();
};
void owners::Owner_280160::FUN_00280160() {
    owners::Owner_280160* p = this;
    int n = 100;
    state = 1;
    do {
        p->clear = 0;
        p->x = 0;
        p->y = 0;
        p = (owners::Owner_280160*)((char*)p + 0x60);
        p = (owners::Owner_280160*)((char*)p - 0x60);
        if (p->first) {
            ((Item_280160*)p->first)->Release();
            p->first = 0;
        }
        if (p->second) {
            ((Item_280160*)p->second)->Release();
            p->second = 0;
        }
        p = (owners::Owner_280160*)((unsigned char*)p + 0x60);
        --n;
    } while (n != 0);
}
