// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 26/26)
// FUN_002a0d00 @ 0x002a0d00
extern "C" double sqrt(double);

struct Vec3_2a0d00 {
    float x, y, z;
};

union FBits_2a0d00 {
    float f;
    unsigned int u;
};

float FUN_00284a10(float t);

class Falloff {
public:
    char pad0[0x18];
    Vec3_2a0d00 center;
    int pad24;
    int pad28;
    int mode;
    float innerX;
    float innerY;
    float innerZ;
    float outerX;
    float outerY;
    float outerZ;
    float sinA;
    float cosA;
    float FUN_002a0d00(const Vec3_2a0d00* p);
};

float Falloff::FUN_002a0d00(const Vec3_2a0d00* p)
{
    if (mode == 0)
        return 1.0f;

    if (mode == 1) {
        float inner = innerX;
        float outer = outerX;
        float dx = p->x - center.x;
        float dy = p->y - center.y;
        float dz = p->z - center.z;
        float len = (float)sqrt(dz * dz + dy * dy + dx * dx);
        if (len <= inner)
            return 1.0f;
        if (!(len < outer))
            return 0.0f;
        return FUN_00284a10((outer - len) / (outer - inner));
    }

    if (mode == 2 || mode == 3) {
        FBits_2a0d00 b;
        float dx = p->x - center.x;
        float dy = p->y - center.y;
        float dz = p->z - center.z;

        b.f = dy;
        b.u &= 0x7fffffff;
        float ady = b.f;
        if (ady >= outerY)
            return 0.0f;

        float rx;
        float rz;
        b.f = sinA;
        b.u &= 0x7fffffff;
        if (b.f <= 0.0001f) {
            rx = dx;
            rz = dz;
        } else {
            rx = dx * cosA + dz * sinA;
            rz = dz * cosA - dx * sinA;
        }

        b.f = rx;
        b.u &= 0x7fffffff;
        float arx = b.f;
        b.f = rz;
        b.u &= 0x7fffffff;
        float arz = b.f;
        if (arx >= outerX)
            return 0.0f;
        if (arz >= outerZ)
            return 0.0f;

        float acc = 1.0f;
        if (arx > innerX)
            acc = FUN_00284a10((outerX - arx) / (outerX - innerX));
        if (ady > innerY)
            acc = FUN_00284a10((outerY - ady) / (outerY - innerY)) * acc;
        if (arz > innerZ)
            acc = FUN_00284a10((outerZ - arz) / (outerZ - innerZ)) * acc;
        return acc;
    }
    return 0.0f;
}
