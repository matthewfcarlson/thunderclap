// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022eb00 @ 0x0022eb00
struct Vec3_22eb00 {
    float x, y, z;
};

struct Vec4_22eb00 {
    float x, y, z, w;
};

// A particle-like integrator: position += velocity, velocity += acceleration.
// The three components are stored one per row (stride 0x10).
class Integrator {
public:
    char pad00[0x40];
    Vec4_22eb00 pos;               // 0x40
    float r50;
    float vx;               // 0x54
    float ax;               // 0x58
    float jx;               // 0x5c
    float r60;
    float vy;               // 0x64
    float ay;               // 0x68
    float jy;               // 0x6c
    float r70;
    float vz;               // 0x74
    float az;               // 0x78
    float jz;               // 0x7c
    void FUN_0022eb00(Vec3_22eb00 *out);
};

void Integrator::FUN_0022eb00(Vec3_22eb00 *out)
{
    pos.x = vx + pos.x;
    pos.y = vy + pos.y;
    pos.z = vz + pos.z;
    vx = ax + vx;
    vy = vy + ay;
    vz = vz + az;
    ax = jx + ax;
    ay = jy + ay;
    az = jz + az;
    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
}
