struct Sub {
    void setA(int a, int b, float c);
    void setB(int a, int b);
};
struct Child {
    void doIt(int a);
};
struct Obj {
    Sub* make();
    Child* child();
};
struct Mgr {
    Obj* get();
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
    Mgr* m1c;
    int m20;
    int m24;
};

void ClimbLocomotionAction::vfunc_4() {
    if (m20) {
        Obj* o = m1c->get();
        Sub* s = o->make();
        if (s) {
            s->setA(m20, 0, -1.0f);
            s->setB(m24, 0);
            Child* c = o->child();
            if (c)
                c->doIt(0);
        }
    }
}
} // namespace motion
} // namespace hulkfight
