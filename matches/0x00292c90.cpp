#include "gen/pure3d.h"

struct Helper_292c90 {
    void run(int, int);
};

void pure3d::Camera::vfunc_23(int a, int b) {
    if (!this->f_cc)
        vfunc_26();
    ((Helper_292c90*)((char*)this + 0x8c))->run(a, b);
}
