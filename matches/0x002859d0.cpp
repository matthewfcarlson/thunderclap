#include "gen/pure3d.h"
#include "decls/data/game/global.h"
// data: gZero_2859d0 = DAT_003f32e0


void pure3d::SimpleFrameController::vfunc_23() {
    (*(unsigned long *)&this->f_20) = 0;
    (*(unsigned long *)&this->f_24) = 0;
    (*(unsigned long *)&this->f_2c) = 0;
    float f;
    if ((*(void * *)&this->f_3c) == 0)
        f = DAT_003f32e0;
    else {
        f = *(float*)((char*)(*(void * *)&this->f_3c) + 0x10) - DAT_003f32dc;
        if (f < DAT_003f32e0)
            f = DAT_003f32e0;
    }
    (*(float *)&this->f_30) = f;
    (*(unsigned long *)&this->f_34) = 0;
    (*(unsigned long *)&this->f_28) = 0x7f7fffff;
    (*(unsigned char (*)[4])&this->f_38)[0] = 1;
    (*(unsigned long *)&this->f_18) = 0x3f800000;
}
