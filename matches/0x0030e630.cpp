struct V3_30e630 {
    int x, y, z;
    void Fix();
};
struct CollisionVolume_30e630 {
    CollisionVolume_30e630();
    virtual void v0();
    char p[0x18];
};
namespace physics {
struct CollisionWall : CollisionVolume_30e630 {
    V3_30e630 a;
    char q[0x0c];
    int k;
    V3_30e630 b;
    int gap;
    V3_30e630 c;
    V3_30e630 d;
    CollisionWall(const V3_30e630* pa, const V3_30e630* pb);
    virtual void v1();
};
} // namespace physics
physics::CollisionWall::CollisionWall(const V3_30e630* pa, const V3_30e630* pb) {
    b = *pb;
    d.x = pa->x;
    d.y = pa->y;
    d.z = pa->z;
    a.x = pa->x;
    a.y = pa->y;
    a.z = pa->z;
    V3_30e630* p = &b;
    p->Fix();
    c.x = p->x;
    c.y = p->y;
    c.z = p->z;
    int* q = &k;
    *q = 0x4e6e6b28;
}
