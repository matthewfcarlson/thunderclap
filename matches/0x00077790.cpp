class CTargetTrack {
  public:
    int a, b, c, d, e;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int CTargetTrack_vftable;
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CTargetTrack* vfunc_5();
};
CTargetTrack* Factory::vfunc_5() {
    CTargetTrack* p = (CTargetTrack*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(unsigned long*)p = (unsigned long)&CTargetTrack_vftable;
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return p;
    }
    return (CTargetTrack*)0;
}