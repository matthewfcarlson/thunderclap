struct Sub_15c940 {
    void setA(int a, int b, float c);
    void setB(int a, int b);
};
struct Child_15c940 {
    void doIt(int a);
};
struct Obj_15c940 {
    Sub_15c940* make();
    Child_15c940* child();
};
struct Mgr_15c940 {
    Obj_15c940* get();
};

namespace hulkfight {
namespace motion {
class ClimbLocomotionAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[0x18];
    Mgr_15c940* m1c;
    int m20;
    int m24;
};

void ClimbLocomotionAction::vfunc_4() {
    if (m20) {
        Obj_15c940* o = m1c->get();
        Sub_15c940* s = o->make();
        if (s) {
            s->setA(m20, 0, -1.0f);
            s->setB(m24, 0);
            Child_15c940* c = o->child();
            if (c)
                c->doIt(0);
        }
    }
}
} // namespace motion
} // namespace hulkfight
