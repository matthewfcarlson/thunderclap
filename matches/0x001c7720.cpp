#include "gen/Render.h"

void Render::StoreBase::FUN_001c7720() {
    int i = 0;
    if (this->f_10 >= 0) {
        do {
            void* p = (*(void ** *)&this->f_14)[i];
            if (p) {
                vfunc_2(p);
                (*(void ** *)&this->f_14)[i] = 0;
            }
            ++i;
        } while (i <= this->f_10);
    }
    this->f_0c = 0;
    this->f_10 = -1;
}
