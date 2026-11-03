#include "compat/ptr.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
class Factory_f27a0 {
  public:
    int Create(int, int);
};
hulk_intptr owners::Holder_f27a0::FUN_000f27a0(hulk_intptr arg) {
    if (data == 0)
        return 0;
    Factory_f27a0* obj = (Factory_f27a0*)Alloc(100);
    int result;
    if (obj != 0)
        result = obj->Create(data, ((int)arg));
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}
