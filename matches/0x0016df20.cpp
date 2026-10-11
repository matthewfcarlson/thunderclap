extern "C" char DAT_004168f8[];
extern void* __cdecl Alloc(unsigned int);
class Obj {
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
    virtual void* Create();
};
void* Factory::Create() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_004168f8);
        *((unsigned char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}