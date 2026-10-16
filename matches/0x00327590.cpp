#include "gen/pure3d.h"

void pure3d::d3dPrimBufferStream::vfunc_6(float a, float b, int i) {
    (*(float * *)&this->f_38)[i * 2] = a;
    (*(float * *)&this->f_38)[i * 2 + 1] = b;
}
