#include "gen/pure3d.h"

struct CompressedQuaternion8_28d1d0 {
    unsigned char data[8];
    float* decode(float*);
};
struct RotationChannel_28d1d0 {
    virtual void a();
    virtual void b();
    virtual void c();
};
struct Quaternion_28d1d0 {
    float a, b, c, d;
};

template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; Quaternion_28d1d0 * out = (Quaternion_28d1d0 *)__p2;

    *time = (float)(*(short * *)&this->f_14)[index];
    float temp[4];
    float* p = ((*(CompressedQuaternion8_28d1d0 * *)&this->f_18) + index)->decode(temp);
    *(Quaternion_28d1d0*)out = *(Quaternion_28d1d0*)p;
}
