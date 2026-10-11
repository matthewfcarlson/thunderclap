extern "C" char DAT_004179e8[];
extern "C" void* FUN_0008d690(unsigned int);
class Base {
  public:
    void init();
};
struct LocomotionStateTrack {
    int vf;
    int pad;
    int m8;
    int mc;
    int m10;
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* TrackFactoryTemplate::vfunc_5() {
    LocomotionStateTrack* p = (LocomotionStateTrack*)FUN_0008d690(0x14);
    if (p) {
        ((Base*)p)->init();
        p->vf = ((int)DAT_004179e8);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}
