// FUN_00224ce0 @ 0x00224ce0
#include "gen/owners.h"
struct Mat4_224ce0 {
    float m[16];
};

struct Quat_224ce0 {
    float q[4];
                             // from rotation matrix
    void FUN_0022b650(Mat4_224ce0 *out);                             // to rotation matrix
     // spherical interpolation
};

// Interpolates two transforms: translation linearly, rotation spherically.
extern "C" void FUN_00224ce0(const Mat4_224ce0 *from, const Mat4_224ce0 *to, float t, Mat4_224ce0 *out) {
    Quat_224ce0 qTo, qFrom, qOut;
    out->m[12] = (to->m[12] - from->m[12]) * t + from->m[12];
    out->m[13] = (to->m[13] - from->m[13]) * t + from->m[13];
    out->m[14] = (to->m[14] - from->m[14]) * t + from->m[14];
    ((owners::Quat_22b370 *)&qFrom)->FUN_0022b370((const float *)(const Mat4_224ce0 *)from);
    ((owners::Quat_22b370 *)&qTo)->FUN_0022b370((const float *)(const Mat4_224ce0 *)to);
    ((owners::Quaternion_22b750 *)&qOut)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_224ce0 *)(&qFrom), (const owners::Quaternion_22b750 *)(const Quat_224ce0 *)(&qTo), t);
    qOut.FUN_0022b650(out);
    out->m[3] = 0;
    out->m[7] = 0;
    out->m[11] = 0;
    out->m[15] = 1.0f;
}
