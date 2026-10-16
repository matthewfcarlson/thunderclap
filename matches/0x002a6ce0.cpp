#include "gen/pure3d.h"

bool pure3d::VertexAnimController::vfunc_26(void* __p0) { int p = (int)__p0;

    if (p && *(int*)(p + 0x28) > 0)
        return *(int*)(p + 0x1c) == 0x58545256;
    return false;
}
