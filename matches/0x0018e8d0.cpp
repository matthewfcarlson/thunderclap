class VarCaster {
  public:
    virtual void f();
};
class TimerCaster {
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
        TimerCaster b;
        p->add(lookup("timerSet", &b));
    }
}