extern "C" void _ReadWriteBarrier();
void* operator new(unsigned int);
struct RenderObjectLoader_2ab7c0 {
    virtual void f0();
    virtual void f1();
    RenderObjectLoader_2ab7c0() throw();
    int x;
};
struct OldParticleEmitterLoader_2ab7c0 : RenderObjectLoader_2ab7c0 {
    OldParticleEmitterLoader_2ab7c0() throw() {}
    virtual void f0();
};
struct SimpleChunkHandler_2ab7c0 {
    virtual void f0();
    virtual void f1();
    int a;
    int b;
    int c;
    int d;
    SimpleChunkHandler_2ab7c0() throw() {
        a = 0;
        b = 0x15800;
        c = 0;
        d = 0;
    }
};
struct OldParticleSystemLoader_2ab7c0 : SimpleChunkHandler_2ab7c0 {
    OldParticleSystemLoader_2ab7c0();
    virtual void f0();
    int m14;
    RenderObjectLoader_2ab7c0* m18;
};
OldParticleSystemLoader_2ab7c0::OldParticleSystemLoader_2ab7c0() {
    m14 = 0;
    m18 = 0;
    OldParticleEmitterLoader_2ab7c0* t = new OldParticleEmitterLoader_2ab7c0;
    _ReadWriteBarrier();
    RenderObjectLoader_2ab7c0* e = t;
    if (e)
        e->f0();
    if (m18)
        m18->f1();
    m18 = e;
}
