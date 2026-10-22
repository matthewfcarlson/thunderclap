class ParticleEmitterHandler_2aaed0 {
  public:
    virtual void Emit();
    ParticleEmitterHandler_2aaed0();
};
class DefaultParticleEmitterHandler : public ParticleEmitterHandler_2aaed0 {
  public:
    virtual void Handle();
    DefaultParticleEmitterHandler();
};
DefaultParticleEmitterHandler::DefaultParticleEmitterHandler() {}
