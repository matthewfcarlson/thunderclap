// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0015f580 @ 0x0015f580
class Counted {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct CountedRef {
    Counted* p;
    CountedRef() : p(0) {}
    CountedRef& operator=(Counted* q)
    {
        if (q)
            q->AddRef();
        if (p)
            p->Release();
        p = q;
        return *this;
    }
};

namespace fight {
class Action {
public:
    Action() throw();
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int, int);
    virtual void vfunc_4();
    virtual bool vfunc_5(int, int);
    char pad4[0x1c - 4];
};
}

namespace hulkfight {
namespace motion {

class ClimbLocomotionAction : public fight::Action {
public:
    ClimbLocomotionAction(Counted* t);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(void*);
    CountedRef target;
    int f_20;
    int f_24;
};

ClimbLocomotionAction::ClimbLocomotionAction(Counted* t) : f_20(0), f_24(0)
{
    target = t;
}

class ClimbLocomotion4Action : public ClimbLocomotionAction {
public:
    ClimbLocomotion4Action(int v, Counted* t);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(void*);
    char pad28[0x20];
    int f_48;
};

ClimbLocomotion4Action::ClimbLocomotion4Action(int v, Counted* t) : ClimbLocomotionAction(t), f_48(0)
{
    f_48 = v;
}

}
}
