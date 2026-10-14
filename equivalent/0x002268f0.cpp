// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002268f0 @ 0x002268f0
extern "C" double sqrt(double);

struct Vec3_2268f0 {
    float x, y, z;
};

float __cdecl FUN_00224f10(Vec3_2268f0 *v);

class Obj_2268f0 {
public:
    char pad0[0x12e4];
    float f12e4;
    float f12e8;
    void FUN_002268f0(Vec3_2268f0 *src);
};

void Obj_2268f0::FUN_002268f0(Vec3_2268f0 *src)
{
    Vec3_2268f0 v;
    v.x = src->x;
    v.y = 0.0f;
    v.z = src->z;
    f12e4 = FUN_00224f10(&v);
    f12e8 = (float)sqrt(v.x * v.x + v.z * v.z + v.y * v.y);
}
