// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fde80 @ 0x000fde80
struct Vec3_fde80 {
    float x, y, z;
};

class Settings_fde80 {
public:
    char pad0[8];
    int f08;                // 0x08
    int f0c;                // 0x0c
    unsigned char flags10[4];   // 0x10
    float f14;              // 0x14
    float f18;              // 0x18
    Vec3_fde80 v1c;               // 0x1c
    Vec3_fde80 v28;               // 0x28
    float f34;              // 0x34
    Vec3_fde80 v38;               // 0x38
    unsigned char b44;      // 0x44
    unsigned char b45;      // 0x45
    unsigned char b46;      // 0x46
    char pad47;
    int f48;                // 0x48
    int f4c;                // 0x4c
    Vec3_fde80 v50;               // 0x50
    Vec3_fde80 v5c;               // 0x5c
    int f68;                // 0x68
    int f6c;                // 0x6c
    unsigned char b70;      // 0x70
    unsigned char b71;      // 0x71
    char pad72[2];
    int f74;                // 0x74
    Vec3_fde80 v78;               // 0x78
    float f84;              // 0x84
    float f88;              // 0x88

    void FUN_000fde80();
};

void Settings_fde80::FUN_000fde80()
{
    f08 = 0;
    f0c = 0;
    flags10[0] = 0;
    flags10[1] = 0;
    flags10[2] = 0;
    flags10[3] = 0;
    f14 = 2.0f;
    f18 = 120.0f;
    v1c.z = 0.0f;
    v1c.y = 0.0f;
    v1c.x = 0.0f;
    v28.z = 0.0f;
    v28.y = 0.0f;
    v28.x = 0.0f;
    f34 = 120.0f;
    v38.z = 0.0f;
    v38.y = 0.0f;
    v38.x = 0.0f;
    b44 = 0;
    b45 = 0;
    b46 = 0;
    f48 = 0;
    f4c = 0;
    v50.z = 0.0f;
    v50.y = 0.0f;
    v50.x = 0.0f;
    v5c.z = 0.0f;
    v5c.y = 0.0f;
    v5c.x = 0.0f;
    f68 = 0;
    f6c = 0;
    b70 = 0;
    b71 = 1;
    f74 = 0;
    v78.z = 0.0f;
    v78.y = 0.0f;
    v78.x = 0.0f;
    f84 = 5.0f;
    f88 = 10.0f;
}
