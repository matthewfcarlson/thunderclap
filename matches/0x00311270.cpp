extern const float zero;
namespace physics {
class ArticulatedPhysicsObject {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void vfunc_17(int, int, int, int, int);
    char p[0x3c];
    float field40;
    char q[0x104];
    unsigned char f148;
    char r[0xb3];
    int* items;
    char s[0x14];
    int field214, field218;
    unsigned char f21c, f21d;
    void first(int, int, int);
};
class Elem {
    char p[0xef];
    unsigned char enabled;

  public:
    void second(int, int);
};
} // namespace physics
void physics::ArticulatedPhysicsObject::vfunc_17(int a1, int a2, int a3, int a4, int a5) {
    if (field40 != zero) {
        f148 = 1;
        f21d = 0;
        if (a4 < 0 || !*((unsigned char*)((char*)items[a4] + 0xef))) {
            f148 = 1;
            return;
        }
        first(a3, a4, a5);
        ((Elem*)items[a4])->second(a1, a2);
        field218 = 0;
        field214 = 0;
        f21c = 0;
    }
}
