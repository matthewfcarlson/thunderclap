// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030d030 @ 0x0030d030
// equiv-map: ??0PhysicsJoint@physics@@QAE@PBUVec3@@MH@Z = 0x0030ca80

struct Vec3 {
    float x, y, z;
};

namespace physics {

class PhysicsJoint {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[2];
    unsigned short word6;
    char pad08[0xf0];
    PhysicsJoint(const Vec3 *axis, float mass, int id);
};

class PhysicsJoint3D : public PhysicsJoint {
public:
    unsigned char flagF8;
    char padf9[3];
    int fFC, f100, f104;
    char pad108[0xc];
    int f114, f118, f11c;
    char pad120[0x18];
    int f138, f13c, f140;
    int f144, f148, f14c;
    unsigned char enabled;      // 0x150
    char pad151[3];
    int f154, f158;
    PhysicsJoint3D(const Vec3 *axis, float mass, int id);
    virtual void vfunc_0();
    virtual void vfunc_1();
};

PhysicsJoint3D::PhysicsJoint3D(const Vec3 *axis, float mass, int id) : PhysicsJoint(axis, mass, id)
{
    flagF8 = 0;
    f154 = 0;
    f158 = 0;
    word6 = 3;
    // the original goes through the vftable here instead of calling the override directly
    PhysicsJoint *self = this;
    self->vfunc_1();
    f140 = 0;
    f13c = 0;
    f138 = 0;
    f14c = 0;
    f148 = 0;
    f144 = 0;
    enabled = 1;
    f104 = 0;
    f100 = 0;
    fFC = 0;
    f11c = 0;
    f118 = 0;
    f114 = 0;
}

}
