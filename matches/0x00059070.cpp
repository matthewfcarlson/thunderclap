extern int vft_59070;
class CSmartPropDistanceCondition {
  public:
    int vptr;
    int pad4[2];
    int one;
    float val;
    char pad14[4];
    class Inner {
      public:
        void init();
    } inner;
    int pad1c;
    int f;
    int g;
    int h;
    void setup(int);
};
void* __cdecl alloc(unsigned int);
class Factory_59070 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual CSmartPropDistanceCondition* create();
};
CSmartPropDistanceCondition* Factory_59070::create() {
    CSmartPropDistanceCondition* p = (CSmartPropDistanceCondition*)alloc(0x30);
    if (p) {
        p->setup(0);
        p->vptr = (int)&vft_59070;
        p->one = 1;
        p->val = 1.0f;
        p->inner.init();
        p->f = 0;
        p->g = 0;
        p->h = 0;
        return p;
    }
    return 0;
}