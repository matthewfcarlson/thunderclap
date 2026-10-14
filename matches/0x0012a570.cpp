extern "C" char DAT_0040fdb4[];
extern void* __cdecl Alloc(int);
class Target_12a570 {
  public:
    void Init(int);
};
class Factory_12a570 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Target_12a570* Make();
};
Target_12a570* Factory_12a570::Make() {
    Target_12a570* p = (Target_12a570*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_0040fdb4);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}