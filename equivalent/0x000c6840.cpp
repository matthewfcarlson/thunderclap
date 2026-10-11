// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000c6840 @ 0x000c6840
struct Vec3 { float x, y, z; };

void FUN_000c6330(Vec3 c0, Vec3 c1, Vec3 c2, Vec3 c3, Vec3 c4, Vec3 c5, Vec3 c6, Vec3 c7,
                  int a, int b);

void FUN_000c6840(Vec3 extent, int a, int b)
{
    float hx = extent.x * 0.5f;
    float hy = extent.y * 0.5f;
    float hz = extent.z * 0.5f;
    Vec3 c0 = { -hx,  hy, -hz };
    Vec3 c1 = {  hx,  hy, -hz };
    Vec3 c2 = { -hx, -hy, -hz };
    Vec3 c3 = {  hx, -hy, -hz };
    Vec3 c4 = { -hx,  hy,  hz };
    Vec3 c5 = {  hx,  hy,  hz };
    Vec3 c6 = { -hx, -hy,  hz };
    Vec3 c7 = {  hx, -hy,  hz };
    FUN_000c6330(c0, c1, c2, c3, c4, c5, c6, c7, a, b);
}
