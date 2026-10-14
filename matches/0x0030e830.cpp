class CollisionVolume {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(float);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
struct Vec3_30e830 {
    float x, y, z;
    void Normalize();
};
namespace physics {
class CollisionWall : public CollisionVolume {
  public:
    char pad[0x44];
    Vec3_30e830 v;
    void vfunc_7(float);
};
} // namespace physics
extern const float one;
void physics::CollisionWall::vfunc_7(float x) {
    Vec3_30e830* p = &v;
    p->Normalize();
    float q = one / x;
    p->x *= q;
    p->y *= q;
    p->z *= q;
    CollisionVolume::f7(x);
}