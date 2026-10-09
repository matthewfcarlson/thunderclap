extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper {
  public:
    void Init();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
struct Orient {
    void* vptr;
    int x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    unsigned char x1c;
    char pad[3];
    int x20;
    int x24;
    int x28;
};
void* Factory::vfunc_5() {
    Orient* p = (Orient*)FUN_0008d690(0x2c);
    if (p) {
        ((Helper*)p)->Init();
        p->xC = 0;
        p->x18 = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->vptr = (void*)0x3fbf68;
        p->x10 = 0xbf800000;
        p->x14 = 0xbc8efa35;
        p->x8 = 1;
        return p;
    }
    return 0;
}
