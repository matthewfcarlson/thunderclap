#include "gen/owners.h"
class Item_90db0 {
  public:
    char pad[0x19];
    unsigned char flag;
    char tail[0x26];
};
void owners::Obj_90db0::FUN_00090db0(int a, int b) {
    int i = 0;
    if (count > 0) {
        Item_90db0* p = (Item_90db0*)this;
        do {
            if (p->flag)
                ((owners::Measure_90790 *)p)->FUN_00090790();
            ++i;
            p = (Item_90db0*)((char*)p + 0x40);
        } while (i < count);
    }
}
