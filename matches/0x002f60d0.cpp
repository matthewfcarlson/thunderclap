class SimulatedObject {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13();
    virtual float vfunc_14();
};
class PhysicsObject : public SimulatedObject {
public:
    char pad[0x1a8 - 4];
    float value;
    char pad2[0x1c4 - 0x1ac];
    unsigned char flag;
    float vfunc_14();
};
float PhysicsObject::vfunc_14() {
    if (flag) return SimulatedObject::vfunc_14();
    return value;
}