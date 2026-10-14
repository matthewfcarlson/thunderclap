// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030e760 @ 0x0030e760
struct Vec3_30e760 {
    float x, y, z;
    void FUN_0022d180();
};

struct Ray_30e760 {
    char pad00[0x1c];
    Vec3_30e760 origin;       // 0x1c
    char pad28[0x34 - 0x28];
    float range;       // 0x34
    Vec3_30e760 dir;          // 0x38
    char pad44[0x48 - 0x44];
    Vec3_30e760 dirCopy;      // 0x48
    Vec3_30e760 start;        // 0x54
    void FUN_003060e0();
    void Init(const Vec3_30e760* from, const Vec3_30e760* direction);
};

void Ray_30e760::Init(const Vec3_30e760* from, const Vec3_30e760* direction)
{
    FUN_003060e0();
    dir = *direction;
    start = *from;
    origin = *from;
    dir.FUN_0022d180();
    dirCopy = dir;
    range = 1.0e9f;
}
