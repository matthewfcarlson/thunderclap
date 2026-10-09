class HitPauseTrack {
  public:
    virtual void A();
    virtual void B();
    HitPauseTrack();
};
extern "C" void* __cdecl operator_new(unsigned int);
class Factory {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual HitPauseTrack* V5();
};
HitPauseTrack* Factory::V5() {
    HitPauseTrack* p = (HitPauseTrack*)operator_new(0x18);
    if (p) {
        p->HitPauseTrack::HitPauseTrack();
        int* q = (int*)p;
        q[0] = 0x4142a0;
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        q[2] = 1;
        return p;
    }
    return 0;
}