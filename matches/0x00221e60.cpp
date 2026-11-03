#include "gen/owners.h"
struct Work_221e60 {
    void First(owners::Obj_221e60*);
};
void owners::Obj_221e60::FUN_00221e60(hulk_uintptr arg) {
    char local[0x40];
    if (state == 1) {
        ((Work_221e60*)((char*)this + 0x40))->First(this);
        state = 0;
    }
    ((owners::Matrix_22ca90 *)(((Work_221e60*)local)))->FUN_0022ca90((const owners::Matrix_22ca90 *)(owners :: Obj_221e60 *)this, (const owners::Matrix_22ca90 *)(hulk_uintptr)(unsigned int)(((unsigned int)arg)));
    struct Block {
        unsigned int a[16];
    };
    *(Block*)this = *(Block*)local;
    state = 2;
}