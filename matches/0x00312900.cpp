extern "C" void _ReadWriteBarrier();
class CollisionVolume_312900 {
  public:
    virtual void f();
    CollisionVolume_312900();
};
struct Z {
    int a, b, c;
    Z() {
        a = 0;
        _ReadWriteBarrier();
        b = 0;
        c = 0;
    }
};
class CollisionAABB : public CollisionVolume_312900 {
  public:
    virtual void f();
    CollisionAABB();
    char pad[0x34];
    Z z;
};
CollisionAABB::CollisionAABB() : CollisionVolume_312900() {}