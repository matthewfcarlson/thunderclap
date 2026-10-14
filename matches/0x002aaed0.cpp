class ParticleEmitterHandlerBase_2aaed0 {
  public:
    virtual void Emit();
    ParticleEmitterHandlerBase_2aaed0();
};
class DefaultParticleEmitterHandler : public ParticleEmitterHandlerBase_2aaed0 {
  public:
    virtual void Handle();
    DefaultParticleEmitterHandler();
};
DefaultParticleEmitterHandler::DefaultParticleEmitterHandler() {}
