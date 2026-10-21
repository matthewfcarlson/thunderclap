// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_5 @ 0x0028d2d0
#include "compat/ptr.h"
struct Quat_28d2d0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_28d2d0 *a, const Quat_28d2d0 *b, float t);
};

struct CompressedQuaternion8 {
    short v[4];
    Quat_28d2d0 *FUN_0028d220(Quat_28d2d0 *tmp);
};

struct Frame_28d2d0 {
    int lo;
    int hi;
    Quat_28d2d0 q1;
    Quat_28d2d0 q0;
    Quat_28d2d0 tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28d2d0 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion8 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat_28d2d0 *out)
{
    Frame_28d2d0 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        hulk_freg dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            hulk_freg frac = dt / (float)span;
            CompressedQuaternion8 *vals = values;
            f.q0 = *vals[f.lo].FUN_0028d220(&f.tmp);
            f.q1 = *vals[hi].FUN_0028d220(&f.tmp);
            out->FUN_0022b750(&f.q0, &f.q1, frac);
            return;
        }
        *out = *values[f.lo].FUN_0028d220(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_0028d220(&f.tmp);
}
