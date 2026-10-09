class ParticleEmitterHandlerBase {
  public:
    virtual void Emit();
    ParticleEmitterHandlerBase();
};
class DefaultParticleEmitterHandler : public ParticleEmitterHandlerBase {
  public:
    virtual void Handle();
    DefaultParticleEmitterHandler();
};
DefaultParticleEmitterHandler::DefaultParticleEmitterHandler() {}
