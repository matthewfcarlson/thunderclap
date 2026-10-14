struct Helper_2ef440 {
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
struct Obj_2ef440 {
    char pad70[0x70];
    SimulatedObject* m70;
    Helper_2ef440* m74;
    void Target(int);
};
void Obj_2ef440::Target(int arg) {
    if (m74)
        m74->Call(arg);
    if (m70) {
        if (dynamic_cast<PhysicsObject*>(m70)) {
            dynamic_cast<PhysicsObject*>(m70)->Finish(arg);
        }
    }
}
