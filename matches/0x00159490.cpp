extern "C" char DAT_00414070[];
class Condition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Init(int);
    char pad[8];
    char flag;
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory_159490 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition* vfunc_5();
};
Condition* Factory_159490::vfunc_5() {
    Condition* p = (Condition*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *((int*)p) = ((int)DAT_00414070);
        p->flag = 1;
        return p;
    }
    return 0;
}