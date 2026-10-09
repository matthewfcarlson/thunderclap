class HitWaitTrack {
  public:
    virtual void V();
    int pad[2];
    int a;
    int b;
    HitWaitTrack();
};
extern void* __cdecl Alloc(unsigned int);
extern int HitWaitTrack_vftable;
class TrackFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual HitWaitTrack* F();
};
HitWaitTrack* TrackFactoryTemplate::F() {
    HitWaitTrack* p = (HitWaitTrack*)Alloc(0x14);
    if (p) {
        p->HitWaitTrack::HitWaitTrack();
        *(int*)p = (int)&HitWaitTrack_vftable;
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}