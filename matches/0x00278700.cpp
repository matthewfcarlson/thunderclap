#include "gen/core.h"

void __stdcall ReleaseThing(int);

int core::XboxSaveDrive::vfunc_20(int __p0) { int * p = (int *)__p0;

    int v = *(int*)((char*)this + *p * 0x208 + 0x2f4);
    if (v != -1) {
        ReleaseThing(v);
        *(int*)((char*)this + *p * 0x208 + 0x2f4) = -1;
    }
    return 1;
}
