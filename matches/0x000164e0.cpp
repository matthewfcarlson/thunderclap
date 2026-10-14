class CSmartPropEventAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int);
    virtual void f7();
    virtual void f8();
    char pad[0x18];
    void* mA;
    int mType;
    void* mB;
};
struct Sub_164e0 {
    int query(int);
};
struct Obj_164e0 {
    char pad[0x40];
    int value;
    char pad2[0xa8];
    Sub_164e0* sub;
    void mutate(int);
    int finish(int);
};
struct A_164e0 {
    void* next();
};
struct B_164e0 {
    void* next();
    Obj_164e0* find(void*);
};
bool CSmartPropEventAction::vfunc_6(int x) {
    A_164e0* a = (A_164e0*)mA;
    void* p = a->next();
    B_164e0* b = (B_164e0*)p;
    p = b->next();
    Obj_164e0* o = ((B_164e0*)p)->find(mB);
    if (o) {
        int old = o->value;
        o->mutate(mType);
        int cur = o->value;
        if (cur != old || mType == 3) {
            int n = o->sub->query(cur);
            if (n > 0)
                o->finish(n);
        }
    }
    return false;
}