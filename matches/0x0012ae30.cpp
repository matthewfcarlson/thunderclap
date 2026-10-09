typedef unsigned char u8;
class CanSeeTargetCondition {
  public:
    int vt;
    char pad[8];
    u8 a;
    u8 b;
    void Init(int);
};
extern void* __cdecl alloc(unsigned int);
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CanSeeTargetCondition* v5();
};
CanSeeTargetCondition* Factory::v5() {
    CanSeeTargetCondition* p = (CanSeeTargetCondition*)alloc(16);
    if (p) {
        p->Init(0);
        p->a = 1;
        p->b = 1;
        p->vt = 0x40ff54;
        return p;
    }
    return 0;
}