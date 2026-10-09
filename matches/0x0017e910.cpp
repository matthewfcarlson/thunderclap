struct Base {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct CriticalMassDrainTrack : Base {
    int pad4;
    int m8;
    int mC;
    int m10;
    void Init();
};
extern "C" void* __cdecl operator_new(unsigned int);
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CriticalMassDrainTrack* Create();
};
CriticalMassDrainTrack* Factory::Create() {
    CriticalMassDrainTrack* p = (CriticalMassDrainTrack*)operator_new(0x14);
    if (p) {
        p->Init();
        *(int*)p = 0x417c28;
        p->mC = 0;
        p->m10 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}