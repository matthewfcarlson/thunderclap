extern "C" char DAT_0041aaa8[];
struct TimerSetTrack {
    int vptr;
    int pad4;
    int m8;
    int mc;
    int m10;
    int m14;
    void Init();
};
extern "C" void* __cdecl Allocate(unsigned int);
class Factory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void* F5();
};
void* Factory::F5() {
    TimerSetTrack* p = (TimerSetTrack*)Allocate(0x18);
    if (p) {
        p->Init();
        p->vptr = ((int)DAT_0041aaa8);
        p->mc = 0;
        p->m10 = 0;
        p->m14 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}