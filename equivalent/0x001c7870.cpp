// STATUS: equivalent (tools/equiv.py level 3: 1510 inputs, branch coverage 10/10)
// FUN_001c7870 @ 0x001c7870
#include "gen/Render.h"

struct StoreBase_nv_1c7870 {
    void FUN_001c7770(int newCapacity);
};

// Stores value in the first empty slot, or appends it (growing the pool when full).

void Render::StoreBase::FUN_001c7870(int unused, int value) {
    if (this->f_0c != 0 && this->f_10 >= 0) {
        int* p = (*(int * *)&this->f_14);
        for (int i = 0; i <= this->f_10; i++) {
            if (p[i] == 0) {
                p[i] = value;
                this->f_0c--;
                return;
            }
        }
    }
    if (this->f_10 == this->f_08 - 1)
        ((StoreBase_nv_1c7870*)this)->FUN_001c7770(this->f_08 * 2);
    this->f_10++;
    (*(int * *)&this->f_14)[this->f_10] = value;
}
