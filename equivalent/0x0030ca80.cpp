// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0030ca80 @ 0x0030ca80
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fd0a0();
};

namespace physics {

class PhysicsJoint {
public:
    virtual void vfunc_0();
    unsigned char flag4;
    unsigned char pad5;
    unsigned short word6;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    float field_30;
    float field_34;
    float field_38;
    float field_3c;
    float field_40;
    float field_44;
    SymMatrix sym48;
    SymMatrix sym64;
    Vec3 vec80;
    Vec3 vec8c;
    char pad98[0xa4 - 0x98];
    Mat4 mat_a4;
    int field_e4;
    int field_e8;
    unsigned char fieldEC;
    unsigned char fieldED;
    unsigned char fieldEE;
    unsigned char fieldEF;
    int field_f0;
    int field_f4;

    PhysicsJoint(const Vec3 *axis, float mass, int id);
};

PhysicsJoint::PhysicsJoint(const Vec3 *axis, float mass, int id)
{
    field_08 = id;
    flag4 = 1;
    word6 = 0;
    field_0c = -1;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_30 = mass;
    field_34 = mass;
    field_3c = mass;
    sym48.FUN_002fca90();
    sym64.FUN_002fca90();
    vec80 = *axis;
    vec8c = *axis;
    field_e4 = 0;
    field_e8 = 0;
    fieldEC = 0;
    fieldED = 1;
    fieldEE = 0;
    fieldEF = 0;
    if (field_34 > 0.0f)
        field_40 = 1.0f / field_3c;
    else
        field_40 = 0;
    field_44 = (float)sqrt(vec8c.x * vec8c.x + vec8c.y * vec8c.y + vec8c.z * vec8c.z);
    mat_a4.FUN_0022b980();
    sym48.FUN_002fd0a0();
    sym64.FUN_002fd0a0();
    field_f0 = 0;
    field_f4 = 0;
    field_38 = field_3c;
}

}
