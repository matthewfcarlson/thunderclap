extern "C" char DAT_004141b0[];
extern "C" void* __cdecl Alloc(unsigned int);
class Cond {
  public:
    Cond(int);
};
class Factory_1599f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Cond* Make();
};
Cond* Factory_1599f0::Make() {
    Cond* p = (Cond*)Alloc(20);
    if (p) {
        p->Cond::Cond(0);
        *(unsigned int*)p = ((int)DAT_004141b0);
        *(unsigned int*)((char*)p + 12) = 0;
        *(unsigned int*)((char*)p + 16) = 0;
        return p;
    }
    return (Cond*)0;
}