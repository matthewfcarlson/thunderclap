#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void FUN_00102a50(int, void*, float*);

bool CSeekBehaviour::vfunc_3(hulk_intptr a, int b, void* __p2, int d, int e) { float * p = (float *)__p2;

    FUN_00102a50(b, (char*)this + 16, p);
    if (this->f_0c) {
        float f = this->f_08;
        *p = f * *p;
        p[1] = f * p[1];
        p[2] = f * p[2];
    }
    return true;
}
