// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002268f0 @ 0x002268f0
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

float __cdecl FUN_00224f10(Vec3 *v);

class Obj {
public:
    char pad0[0x12e4];
    float f12e4;
    float f12e8;
    void FUN_002268f0(Vec3 *src);
};

void Obj::FUN_002268f0(Vec3 *src)
{
    Vec3 v;
    v.x = src->x;
    v.y = 0.0f;
    v.z = src->z;
    f12e4 = FUN_00224f10(&v);
    f12e8 = (float)sqrt(v.x * v.x + v.z * v.z + v.y * v.y);
}
