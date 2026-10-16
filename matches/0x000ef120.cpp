#include "gen/global.h"

struct FEContainer_nv_ef120 {
    void helper(int);
};

void FEContainer::vfunc_6() {
    ((FEContainer_nv_ef120*)this)->helper(8);
    int state = *(int*)((char*)(*(void * *)&this->f_04) + 0x17f8);
    if (state == 0)
        ((FEContainer_nv_ef120*)this)->helper(0xc);
    state = *(int*)((char*)(*(void * *)&this->f_04) + 0x17f8);
    if (state == 1)
        ((FEContainer_nv_ef120*)this)->helper(0xd);
}
