typedef unsigned __int64 U64;
struct Base {
    virtual void v0();
    Base(int, int);
    char pad[0x60];
    void* particle;
};
struct Particle {
    virtual void AddRef();
};
struct Caster {
    virtual void cast();
};
struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Particle* Get(Caster*, U64);
    inline Particle* Fetch(U64 id) {
        Caster caster;
        return Get(&caster, id);
    }
};
extern Loader* gLoader;
extern U64 __cdecl Find(int);
struct FEParticleAnimation : Base {
    virtual void v0();
    FEParticleAnimation(int a, int b, int c);
};
FEParticleAnimation::FEParticleAnimation(int a, int b, int c) : Base(a, b) {
    Loader* l = gLoader;
    U64 id = Find(b);
    particle = l->Fetch(id);
    if (particle)
        ((Particle*)particle)->AddRef();
}
