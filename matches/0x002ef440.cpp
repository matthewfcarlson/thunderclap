struct Helper {
    void Call(int);
};
class SimulatedObject {
  public:
    virtual void v0();
};
class PhysicsObject : public SimulatedObject {
  public:
    virtual void v1();
    void Finish(int);
};
struct Obj {
    char pad70[0x70];
    SimulatedObject* m70;
    Helper* m74;
    void Target(int);
};
void Obj::Target(int arg) {
    if (m74)
        m74->Call(arg);
    if (m70) {
        if (dynamic_cast<PhysicsObject*>(m70)) {
            dynamic_cast<PhysicsObject*>(m70)->Finish(arg);
        }
    }
}
