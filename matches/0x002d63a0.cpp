struct Sub_2d63a0 {
    void Init();
    char pad[0x114];
};
struct ParticleEmitter_2d63a0 {
    ParticleEmitter_2d63a0();
    virtual void V1();
};
struct SpriteParticleEmitter_2d63a0 : ParticleEmitter_2d63a0 {
    SpriteParticleEmitter_2d63a0();
    virtual void V1();
    char pad[0xa8 - 4];
    Sub_2d63a0 sub;
    int f1bc, f1c0, f1c4, f1c8, f1cc, f1d0, f1d4, f1d8;
};
SpriteParticleEmitter_2d63a0::SpriteParticleEmitter_2d63a0() {
    sub.Init();
    f1bc = 0;
    f1c0 = 0;
    f1c4 = 0;
    f1c8 = 0;
    f1cc = 0;
    f1d4 = 0;
    f1d8 = 0;
}
