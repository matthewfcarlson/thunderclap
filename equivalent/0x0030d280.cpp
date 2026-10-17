// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::PhysicsJoint3D::vfunc_24 @ 0x0030d280
namespace physics {
struct Vec3 { float x, y, z; };
struct PhysicsJoint3D {
    char pad[0x120];
    Vec3 position;
    char pad2[0x151 - 0x12c];
    unsigned char dirty;
    void vfunc_24(const Vec3 *delta);
};
void PhysicsJoint3D::vfunc_24(const Vec3 *delta) {
    position.x += delta->x;
    position.y += delta->y;
    position.z += delta->z;
    dirty = 0;
}
}