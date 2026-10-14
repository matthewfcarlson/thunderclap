extern "C" char DAT_00428b64[];
class Factory_23d780 {
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
class Init_23d780 {
  public:
    void InitFn(int);
};
extern "C" void* __cdecl Alloc(unsigned int);
void* Factory_23d780::V5() {
    Factory_23d780* p = (Factory_23d780*)Alloc(0x14);
    if (p) {
        ((Init_23d780*)p)->InitFn(0);
        *(unsigned long*)p = ((int)DAT_00428b64);
        p->m0c = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}