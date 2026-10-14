// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e09b0 @ 0x000e09b0
struct Vec3_e09b0 { float x, y, z; };
extern int __cdecl FUN_000e0850(Vec3_e09b0 a, Vec3_e09b0 b, Vec3_e09b0 c, Vec3_e09b0 d, unsigned int e, unsigned int f);
int __cdecl FUN_000e09b0(float x1, float y1, float z1, float x2, float y2, float z2, unsigned int e, unsigned int f)
{
    Vec3_e09b0 a = { x1, y1, 0.0f };
    Vec3_e09b0 b = { x2, y1, 0.0f };
    Vec3_e09b0 c = { x1, y2, 0.0f };
    Vec3_e09b0 d = { x2, y2, 0.0f };
    return FUN_000e0850(a, b, c, d, e, f);
}