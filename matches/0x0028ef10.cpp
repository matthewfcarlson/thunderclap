class Target {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void set(int, int);
};
class Shader {
    char pad[16];

  public:
    Target* target;
};
class ShaderColourBroadcast {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Shader* vfunc_3(Shader*);
    virtual void f4();
    virtual void f5();
    int pad, a;
    volatile int b;
};
Shader* ShaderColourBroadcast::vfunc_3(Shader* s) {
    if (s) {
        int y = b;
        int x = a;
        s->target->set(x, y);
    }
    return s;
}