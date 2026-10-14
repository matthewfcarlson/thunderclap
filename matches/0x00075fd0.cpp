extern "C" char DAT_003fba38[];
extern "C" void* __cdecl Allocate(unsigned int);
class Init_75fd0 {
  public:
    void InitFn();
};
class Factory_75fd0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
void* Factory_75fd0::Make() {
    void* p = Allocate(0x14);
    if (p) {
        ((Init_75fd0*)p)->InitFn();
        *(unsigned int*)p = ((int)DAT_003fba38);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        *(unsigned int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}