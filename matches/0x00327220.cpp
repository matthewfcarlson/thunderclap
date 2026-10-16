#include "gen/pure3d.h"

void pure3d::d3dPrimBuffer::vfunc_8(unsigned int x) {
    *((unsigned char*)this + 0x35) = 0;
    *((unsigned int*)this + 9) = x;
}
