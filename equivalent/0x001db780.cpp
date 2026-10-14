// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001db780 @ 0x001db780
struct Quat {
    float x, y, z, w;
    void FUN_0022b560(const Quat *other);
};

struct PackedRotation {
    short x, y, z;

    void FUN_001db780(const Quat *q);
};

void PackedRotation::FUN_001db780(const Quat *q)
{
    Quat a = *q;
    Quat identity;
    identity.x = 0.0f;
    identity.y = 0.0f;
    identity.z = 0.0f;
    identity.w = 1.0f;
    a.FUN_0022b560(&identity);
    x = (short)(a.x * 32767.0f);
    y = (short)(a.y * 32767.0f);
    z = (short)(a.z * 32767.0f);
}
