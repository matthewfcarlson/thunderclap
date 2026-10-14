// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00224ce0 @ 0x00224ce0
struct Mat4 {
    float m[16];
};

struct Quat {
    float q[4];
    void FUN_0022b370(const Mat4 *m);                         // from rotation matrix
    void FUN_0022b650(Mat4 *out);                             // to rotation matrix
    void FUN_0022b750(const Quat *a, const Quat *b, float t); // spherical interpolation
};

// Interpolates two transforms: translation linearly, rotation spherically.
void FUN_00224ce0(const Mat4 *from, const Mat4 *to, float t, Mat4 *out) {
    Quat qTo, qFrom, qOut;
    out->m[12] = (to->m[12] - from->m[12]) * t + from->m[12];
    out->m[13] = (to->m[13] - from->m[13]) * t + from->m[13];
    out->m[14] = (to->m[14] - from->m[14]) * t + from->m[14];
    qFrom.FUN_0022b370(from);
    qTo.FUN_0022b370(to);
    qOut.FUN_0022b750(&qFrom, &qTo, t);
    qOut.FUN_0022b650(out);
    out->m[3] = 0;
    out->m[7] = 0;
    out->m[11] = 0;
    out->m[15] = 1.0f;
}
