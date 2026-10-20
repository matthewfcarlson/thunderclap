#include "gen/pure3d.h"

namespace math {
struct Quaternion {
    float x, y, z, w;
};
struct CompressedQuaternion3_28db60 {
    unsigned char bytes[3];
    Quaternion* FUN_0028dbb0(Quaternion* result);
};
} // namespace math
namespace pure3d {
} // namespace pure3d
template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; math::Quaternion * rotation = (math::Quaternion *)__p2;

    *time = (float)(*(short * *)&this->f_14)[index];
    math::Quaternion temp;
    math::Quaternion* decoded = (*(math::CompressedQuaternion3_28db60 * *)&this->f_18)[index].FUN_0028dbb0(&temp);
    *rotation = *decoded;
}
