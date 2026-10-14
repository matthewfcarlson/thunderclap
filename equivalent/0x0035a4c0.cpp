// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035a4c0 @ 0x0035a4c0
// Oriented-box overlap against the world axes: the same test as FUN_0035a2a0 with an identity basis.
struct Vec3_35a4c0 {
    float x, y, z;
};

char __cdecl FUN_0035a2a0(Vec3_35a4c0 *a1, Vec3_35a4c0 *a2, Vec3_35a4c0 *axisX, Vec3_35a4c0 *axisY, Vec3_35a4c0 *axisZ, Vec3_35a4c0 *v0, Vec3_35a4c0 *v1, Vec3_35a4c0 *v2,
                          Vec3_35a4c0 *normal, float *depth, Vec3_35a4c0 *centre, Vec3_35a4c0 *outN, int f1, int f2, int f4);

char __cdecl FUN_0035a4c0(Vec3_35a4c0 *a1, Vec3_35a4c0 *a2, Vec3_35a4c0 *v0, Vec3_35a4c0 *v1, Vec3_35a4c0 *v2, Vec3_35a4c0 *normal, float *depth,
                          Vec3_35a4c0 *centre, Vec3_35a4c0 *outN, int f1, int f2, int f4)
{
    struct Frame {
        Vec3_35a4c0 axisZ;
        Vec3_35a4c0 axisY;
        Vec3_35a4c0 axisX;
    } fr;
    fr.axisZ.x = 0.0f; fr.axisZ.y = 0.0f; fr.axisZ.z = 1.0f;
    fr.axisY.x = 0.0f; fr.axisY.y = 1.0f; fr.axisY.z = 0.0f;
    fr.axisX.x = 1.0f; fr.axisX.y = 0.0f; fr.axisX.z = 0.0f;
    return FUN_0035a2a0(a1, a2, &fr.axisX, &fr.axisY, &fr.axisZ, v0, v1, v2, normal, depth, centre, outN, f1, f2, f4);
}
