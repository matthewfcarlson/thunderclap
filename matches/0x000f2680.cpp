#include "decls/data/game/global.h"
// data: gLoader = DAT_004dd9cc

typedef unsigned __int64 U64;
struct FEPoseAnimation_f2680 {
    virtual void v0();
    FEPoseAnimation_f2680(int, int);
    char pad[0x60];
    void* particle;
};
struct Particle {
    virtual void AddRef();
};
struct DynamicCaster_f2680 {
    virtual void cast();
};
struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Particle* Get(DynamicCaster_f2680*, U64);
    inline Particle* Fetch(U64 id) {
        DynamicCaster_f2680 caster;
        return Get(&caster, id);
    }
};
extern U64 __cdecl Find(int);
struct FEParticleAnimation : FEPoseAnimation_f2680 {
    virtual void v0();
    FEParticleAnimation(int a, int b, int c);
};
FEParticleAnimation::FEParticleAnimation(int a, int b, int c) : FEPoseAnimation_f2680(a, b) {
    Loader* l = (*(Loader**)&DAT_004dd9cc);
    U64 id = Find(b);
    particle = l->Fetch(id);
    if (particle)
        ((Particle*)particle)->AddRef();
}
