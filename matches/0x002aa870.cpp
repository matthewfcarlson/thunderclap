class OldParticleSystemLoader {
  public:
    OldParticleSystemLoader();
    virtual void A();
};
class OldParticleEmitterLoader : public OldParticleSystemLoader {
  public:
    OldParticleEmitterLoader();
};
OldParticleEmitterLoader::OldParticleEmitterLoader() : OldParticleSystemLoader() {}