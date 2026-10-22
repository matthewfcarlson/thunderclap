class Item {
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
    virtual unsigned int Count();
};
class SimpleFrameController_2a71d0 {
  public:
    virtual unsigned char vfunc_22();
};
class ParticleController : public SimpleFrameController_2a71d0 {
    char pad[0x4c];
    Item** begin;
    Item** end;

  public:
    virtual unsigned char vfunc_22();
};
unsigned char ParticleController::vfunc_22() {
    if (SimpleFrameController_2a71d0::vfunc_22() == 1) {
        for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) {
            if (begin[i]->Count() > 0)
                return 0;
        }
        return 1;
    }
    return 0;
}