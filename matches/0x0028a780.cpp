#include "gen/pure3d.h"

struct V3_28a780 {
    int x, y, z;
};

void pure3d::Vector3DOFChannel::vfunc_3(int index, void* __p1, void* __p2) { float * outIndex = (float *)__p1; V3_28a780 * outValue = (V3_28a780 *)__p2;

    *outIndex = (float)(*(short * *)&this->f_14)[index];
    V3_28a780* p = (*(V3_28a780 * *)&this->f_18) + index;
    int a = p->x;
    V3_28a780* q = p;
    outValue->x = a;
    outValue->y = q->y;
    outValue->z = q->z;
}
