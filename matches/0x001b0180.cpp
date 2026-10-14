struct Owner_1b0180 {
    char pad[0x148];
    void* mLink;
};
struct Obj_1b0180 {
    char pad[8];
    Owner_1b0180* mOwner;
    int mType;
};
struct Handle_1b0180 {
    char pad[0x18];
    Obj_1b0180* mObj;
};

class AICollisionSolverAgent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual bool vfunc_10(Handle_1b0180* a, Handle_1b0180* b);
    virtual void f11();
};

bool AICollisionSolverAgent::vfunc_10(Handle_1b0180* a, Handle_1b0180* b) {
    Obj_1b0180* x = a->mObj;
    Obj_1b0180* y = b->mObj;
    if (!x || !y)
        return false;
    int tx = x->mType;
    int ty = y->mType;
    if (tx == 2) {
        if (ty != 5)
            return false;
    }
    if (ty == 2) {
        if (tx != 5)
            return false;
    } else if (tx == 5 && ty == 1) {
        Owner_1b0180* o = x->mOwner;
        if (o && o->mLink && o->mLink == (void*)y->mOwner)
            return false;
    } else if (ty == 5 && tx == 1) {
        Owner_1b0180* o = y->mOwner;
        if (o && o->mLink && o->mLink == (void*)x->mOwner)
            return false;
    }
    return true;
}
