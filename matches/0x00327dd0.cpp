class Obj_327dd0 {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};
extern Obj_327dd0* gObj_327dd0;
extern int gState_327dd0;
void target() {
    Obj_327dd0* p = gObj_327dd0;
    gState_327dd0 = -1;
    gObj_327dd0 = 0;
    if (p)
        p->f13();
}