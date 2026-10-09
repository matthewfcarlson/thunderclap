class HitPushbackCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(void*, void*, void*);
    char pad[8];
    unsigned char value;
};
extern int Cast(void*, int, void*, void*, int);
struct Obj {
    Obj* A();
    Obj* B();
    unsigned char C();
};
bool HitPushbackCondition::v6(void* a, void* params, void* c) {
    if (!Cast(params, 0, (void*)0x494b44, (void*)0x494b60, 0))
        return false;
    Obj* x = ((Obj*)params)->A();
    Obj* y = x->B();
    unsigned char z = y->C();
    return (unsigned char)(z - value) == 0;
}
