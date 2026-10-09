class ParticleEmitterHandlerBase {
  public:
    ParticleEmitterHandlerBase();
    virtual void B();
};
class ParticleEmitterLoader {
  public:
    class ParticleEmitterHandler : public ParticleEmitterHandlerBase {
      public:
        ParticleEmitterHandler();
        virtual void F();
    };
};
ParticleEmitterLoader::ParticleEmitterHandler::ParticleEmitterHandler() {}
