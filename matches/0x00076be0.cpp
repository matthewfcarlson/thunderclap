extern "C" char DAT_003fbe04[];
class CIntangibleTrack {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    int c;
    int d;
    int e;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Factory {
  public:
    CIntangibleTrack* vfunc_5();
};
CIntangibleTrack* Factory::vfunc_5() {
    CIntangibleTrack* p = (CIntangibleTrack*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fbe04);
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return p;
    }
    return 0;
}