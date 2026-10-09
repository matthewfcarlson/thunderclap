extern void* __cdecl Alloc(int);
class Target {
  public:
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Target* Make();
};
Target* Factory::Make() {
    Target* p = (Target*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = 0x40fdb4;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}