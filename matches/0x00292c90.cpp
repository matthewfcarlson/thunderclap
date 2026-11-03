#include "gen/pure3d.h"
#include "gen/owners.h"

struct Helper_292c90 {
};

void pure3d::Camera::vfunc_23(int a, int b) {
    if (!this->f_cc)
        vfunc_26();
    ((owners::Mat_22c2b0 *)(((Helper_292c90*)((char*)this + 0x8c))))->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
}
