class HitPushbackCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    unsigned char flag;
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual HitPushbackCondition* Make();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern int vtable;
HitPushbackCondition* Factory::Make() {
    HitPushbackCondition* p = (HitPushbackCondition*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(int*)p = (int)&vtable;
        p->flag = 1;
        return p;
    }
    return 0;
}