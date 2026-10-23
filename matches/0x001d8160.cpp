namespace physics {
class SimulatedObject {
  public:
    virtual void s00();
};
class PhysicsObject : public SimulatedObject {
  public:
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual float s36();
};
}  // namespace physics
struct Inner {
    char pad[0x70];
    physics::SimulatedObject* object;
    inline physics::PhysicsObject* cast() { return dynamic_cast<physics::PhysicsObject*>(object); }
};
struct Middle {
    char pad[0x10];
    Inner* inner;
};
struct Owner {
    char pad[0xa0];
    Middle* middle;
    float FUN_001d8160();
};
float Owner::FUN_001d8160() {
    if (middle && middle->inner && middle->inner->object) {
        physics::PhysicsObject* result = middle->inner->cast();
        if (result)
            return result->s36();
    }
    return 1.0f;
}