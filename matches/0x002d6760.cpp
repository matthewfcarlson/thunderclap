extern void* vftable_2d6760;
class SpriteParticleRenderer {
  public:
    SpriteParticleRenderer();
    void* vf;
    int x;
};
SpriteParticleRenderer::SpriteParticleRenderer() {
    x = 0;
    vf = &vftable_2d6760;
}