class LocomotionStrafe4Track { public: int Init(); };
class TrackFactoryTemplate {
public:
    virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e();
    virtual int vfunc_5();
};
extern "C" void* __cdecl Alloc(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    LocomotionStrafe4Track* p = (LocomotionStrafe4Track*)Alloc(0xa8);
    if (p) return p->Init();
    return 0;
}
