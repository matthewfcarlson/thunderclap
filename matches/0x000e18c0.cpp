class FEDoAction { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); }; 
class FEDoParticleSystem : public FEDoAction { public: virtual void p0(); virtual void p1(); virtual void vfunc_2(); virtual void v5(); char pad[0x30]; FEDoAction* mTarget; };
void FEDoParticleSystem::vfunc_2() { mTarget->v2(); }