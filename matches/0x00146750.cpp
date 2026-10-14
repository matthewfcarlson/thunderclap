extern "C" char DAT_00413004[];
class Factory_146750 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* vfunc_5();
};
class Motion_146750 {
  public:
    void Init();
};
extern void* __cdecl Alloc(unsigned int);
void* Factory_146750::vfunc_5() {
    Motion_146750* p = (Motion_146750*)Alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_00413004);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return (void*)((char*)p - (char*)p);
}