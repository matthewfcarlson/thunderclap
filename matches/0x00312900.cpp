extern "C" void _ReadWriteBarrier();
class Collision {
  public:
    virtual void f();
    Collision();
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
class CollisionAABB : public Collision {
  public:
    virtual void f();
    CollisionAABB();
    char pad[0x34];
    Z z;
};
CollisionAABB::CollisionAABB() : Collision() {}