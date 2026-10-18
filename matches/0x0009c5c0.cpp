struct P9C5C0_9c5c0 {
    char a;
    char pad[3];
    char b;
    char pad2[3];
    char c;
};
class Mgr_9c5c0 {
  public:
    void f(unsigned char, unsigned char, unsigned char);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Closure3 : public Function {
  public:
    char pad[0x1c - 4];
    void (Mgr_9c5c0::*mFn)(unsigned char, unsigned char, unsigned char);
    Mgr_9c5c0* mObj;
    virtual void vfunc_2(void*, P9C5C0_9c5c0*, void*);
};
void Closure3::vfunc_2(void* a, P9C5C0_9c5c0* p, void* c) {
    char t = p->a;
    p->a = t;
    (mObj->*mFn)((unsigned char)t, (unsigned char)p->b, (unsigned char)p->c);
}
