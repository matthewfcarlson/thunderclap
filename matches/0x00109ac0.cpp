#include "gen/global.h"

void FUN_00102bf0(int, void*, int, float*);

bool CArriveBehaviour::vfunc_3(int a, int b, void* __p2, int c, int e) { float * out = (float *)__p2;

    FUN_00102bf0(b, (*(char (*)[12])&this->f_10), this->f_1c, out);
    if (this->f_0c) {
        float f = this->f_08;
        out[0] = f * out[0];
        out[1] = f * out[1];
        out[2] = f * out[2];
    }
    return true;
}
