#include "gen/pure3d.h"

struct CompressedQuaternion4_28d7d0 {
    unsigned int x[4];
};
struct PackedQ {
    unsigned int v;
    CompressedQuaternion4_28d7d0* Decode(CompressedQuaternion4_28d7d0* tmp);
};

template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; CompressedQuaternion4_28d7d0 * out = (CompressedQuaternion4_28d7d0 *)__p2;

    int value = (*(short * *)&this->f_14)[index];
    *time = (float)value;
    CompressedQuaternion4_28d7d0 temp;
    CompressedQuaternion4_28d7d0* p = (*(PackedQ * *)&this->f_18)[index].Decode(&temp);
    *out = *p;
}
