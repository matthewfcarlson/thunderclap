extern void* __cdecl FUN_0008d690(unsigned int);
class Temp {
  public:
    virtual void V();
    char pad[8];
    int x;
    int y;
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
    Temp* p = (Temp*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = 0x416678;
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}