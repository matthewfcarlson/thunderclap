// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000e11a0 @ 0x000e11a0
struct Vec3_e11a0 { float x, y, z; };

void FUN_000e0e50(Vec3_e11a0 c0, Vec3_e11a0 c1, Vec3_e11a0 c2, Vec3_e11a0 c3, Vec3_e11a0 c4, Vec3_e11a0 c5, Vec3_e11a0 c6, Vec3_e11a0 c7,
                  int a, int b);

void FUN_000e11a0(Vec3_e11a0 extent, int a, int b)
{
    float hx = extent.x * 0.5f;
    float hy = extent.y * 0.5f;
    float hz = extent.z * 0.5f;
    Vec3_e11a0 c0 = { -hx,  hy, -hz };
    Vec3_e11a0 c1 = {  hx,  hy, -hz };
    Vec3_e11a0 c2 = { -hx, -hy, -hz };
    Vec3_e11a0 c3 = {  hx, -hy, -hz };
    Vec3_e11a0 c4 = { -hx,  hy,  hz };
    Vec3_e11a0 c5 = {  hx,  hy,  hz };
    Vec3_e11a0 c6 = { -hx, -hy,  hz };
    Vec3_e11a0 c7 = {  hx, -hy,  hz };
    FUN_000e0e50(c0, c1, c2, c3, c4, c5, c6, c7, a, b);
}
