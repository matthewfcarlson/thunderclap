// FUN_000a0ac0 @ 0x000a0ac0
struct Vec3_a0ac0 { float x, y, z; };

extern void __cdecl FUN_000a04c0(Vec3_a0ac0* d, float* a, float* b, float* len);
extern float __cdecl FUN_000a02a0(float angle);

struct Aim_a0ac0 {
    char pad0[0x194];
    Vec3_a0ac0 origin;          // 0x194
    char pad1[0x1e8 - 0x1a0];
    Vec3_a0ac0 target;          // 0x1e8
    char pad2[0x20c - 0x1f4];
    float yawBase;        // 0x20c
    float pitchBase;      // 0x210
    float yawOut;         // 0x214
    char pad3[0x21c - 0x218];
    float yawBias;        // 0x21c
    char pad4[0x224 - 0x220];
    float pitchOut;       // 0x224
    char pad5[0x2ec - 0x228];
    float s2ec, s2f0;
    char pad6[0x2fc - 0x2f4];
    float s2fc, s300;

    void FUN_000a0ac0(float pitch0, float yaw);
};

void Aim_a0ac0::FUN_000a0ac0(float pitch0, float yaw)
{
    Vec3_a0ac0 d;
    float len;
    d.x = target.x - origin.x;
    d.y = target.y - origin.y;
    d.z = target.z - origin.z;
    FUN_000a04c0(&d, &pitchBase, &yawBase, &len);
    float pitch = FUN_000a02a0(pitch0 - pitchBase);
    pitchOut = pitch;
    float v = (yaw - yawBase) - yawBias;
    yawOut = v;
    s300 = pitch;
    s2fc = pitch;
    s2f0 = v;
    s2ec = v;
}
