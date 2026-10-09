extern "C" void* __cdecl Alloc(unsigned int);
class Cond {
  public:
    Cond(int);
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Cond* Make();
};
Cond* Factory::Make() {
    Cond* p = (Cond*)Alloc(20);
    if (p) {
        p->Cond::Cond(0);
        *(unsigned int*)p = 0x4141b0;
        *(unsigned int*)((char*)p + 12) = 0;
        *(unsigned int*)((char*)p + 16) = 0;
        return p;
    }
    return (Cond*)0;
}