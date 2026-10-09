extern void* vftable;
class SpriteParticleRenderer {
  public:
    SpriteParticleRenderer();
    void* vf;
    int x;
};
SpriteParticleRenderer::SpriteParticleRenderer() {
    x = 0;
    vf = &vftable;
}