struct V3 {
    int x, y, z;
    void Fix();
};
struct Base {
    Base();
    virtual void v0();
    char p[0x18];
};
namespace physics {
struct CollisionWall : Base {
    V3 a;
    char q[0x0c];
    int k;
    V3 b;
    int gap;
    V3 c;
    V3 d;
    CollisionWall(const V3* pa, const V3* pb);
    virtual void v1();
};
} // namespace physics
physics::CollisionWall::CollisionWall(const V3* pa, const V3* pb) {
    b = *pb;
    d.x = pa->x;
    d.y = pa->y;
    d.z = pa->z;
    a.x = pa->x;
    a.y = pa->y;
    a.z = pa->z;
    V3* p = &b;
    p->Fix();
    c.x = p->x;
    c.y = p->y;
    c.z = p->z;
    int* q = &k;
    *q = 0x4e6e6b28;
}
