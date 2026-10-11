extern "C" char DAT_00428b64[];
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* V5();
    char pad[8];
    int m0c;
    int m10;
};
class Init {
  public:
    void InitFn(int);
};
extern "C" void* __cdecl Alloc(unsigned int);
void* Factory::V5() {
    Factory* p = (Factory*)Alloc(0x14);
    if (p) {
        ((Init*)p)->InitFn(0);
        *(unsigned long*)p = ((int)DAT_00428b64);
        p->m0c = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}