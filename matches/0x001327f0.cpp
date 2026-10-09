extern "C" void* __cdecl Alloc(unsigned int);
class Obj {
  public:
    void Init(int);
    char pad[12];
    int z;
    char c;
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj* Make();
};
Obj* Factory::Make() {
    Obj* p = (Obj*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = 0x411244;
        p->z = 0;
        p->c = 0;
        return p;
    }
    return 0;
}