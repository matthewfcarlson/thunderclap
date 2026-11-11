// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028d130..0x0028df60 (kind game, layer engine, confidence high), dominant class math::CompressedQuaternion3
// (tree_prelude.h: not needed)


// 0x0028d1d0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_3 (75 B): matches/0x0028d1d0.cpp [isolated: lost its match in the tree (call sequence differs); on include/gen/ and not mergeable]
// sym: ?vfunc_3@?$CompressedQuaternionChannel@VCompressedQuaternion8@math@@@pure3d@@UAEXHPAX0@Z
#include "gen/pure3d.h"
#include "gen/owners.h"

struct CompressedQuaternion8_28d1d0 {
    unsigned char data[8];
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
    float* p = ((owners::Quat16_28d220 *)(((*(CompressedQuaternion8_28d1d0 * *)&this->f_18) + index)))->FUN_0028d220(temp);
    *(Quaternion_28d1d0*)out = *(Quaternion_28d1d0*)p;
}

