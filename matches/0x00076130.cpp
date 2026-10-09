extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CComboTimerTrack {
  public:
    CComboTimerTrack();
    int a[6];
};
extern int CComboTimerTrack_vftable;
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
    CComboTimerTrack* p = (CComboTimerTrack*)FUN_0008d690(0x18);
    if (p) {
        p->CComboTimerTrack::CComboTimerTrack();
        *(int**)p = &CComboTimerTrack_vftable;
        p->a[3] = 0;
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[2] = 1;
        return p;
    }
    return 0;
}
