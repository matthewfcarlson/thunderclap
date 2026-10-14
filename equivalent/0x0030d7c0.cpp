// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030d7c0 @ 0x0030d7c0
struct Vec3_30d7c0 { float x, y, z; };
struct Target_30d7c0 {
    char pad0[0x14];
    Vec3_30d7c0 sumA;
    Vec3_30d7c0 sumB;
    char pad1[0x88 - 0x2c];
    int n;
    float f8c;
    float f90;
    void FUN_0030d7c0(Vec3_30d7c0 *a, Vec3_30d7c0 *b, float c, float d);
};
void Target_30d7c0::FUN_0030d7c0(Vec3_30d7c0 *a, Vec3_30d7c0 *b, float c, float d)
{
    sumA.x = sumA.x + a->x;
    sumA.y = a->y + sumA.y;
    sumA.z = a->z + sumA.z;
    sumB.x = sumB.x + b->x;
    sumB.y = b->y + sumB.y;
    sumB.z = b->z + sumB.z;
    n = n + 1;
    f8c = c + f8c;
    f90 = d + f90;
}
