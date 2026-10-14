extern void* __cdecl Allocate(unsigned int);
extern void* TargetTypeCondition_vftable[];
class Cond {
  public:
    Cond(int);
    virtual void a();
    char pad[0xc - 4];
    int x;
    int y;
};
class Factory_12a360 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Cond* F();
};
Cond* Factory_12a360::F() {
    Cond* p = (Cond*)Allocate(0x14);
    if (p) {
        p->Cond::Cond(0);
        *(void* volatile*)p = TargetTypeCondition_vftable;
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}
