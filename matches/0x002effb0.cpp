class Other {
  public:
    void Use(int a, int b);
};
namespace physics {
class CollisionSphere {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void vfunc_11(Other* p);
};
void CollisionSphere::vfunc_11(Other* p) {
    p->Use(v4(), v4());
}
} // namespace physics