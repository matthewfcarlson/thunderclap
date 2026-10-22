class VarCaster {
  public:
    virtual void f();
};
class TrackFactoryCasterTemplate_18e8d0 {
  public:
    virtual void f();
};
extern void* lookup(const char*, void*);
class Factory {
  public:
    void add(void*);
};
void setup(Factory* p) {
    {
        VarCaster a;
        p->add(lookup("varAssign", &a));
    }
    {
        TrackFactoryCasterTemplate_18e8d0 b;
        p->add(lookup("timerSet", &b));
    }
}