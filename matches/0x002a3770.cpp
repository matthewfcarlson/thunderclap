class DrawableContainer {
  public:
    int vfunc_16();
};
class ParticleSystem : public DrawableContainer {
  public:
    char pad[0xa4 - sizeof(DrawableContainer)];
    int mValue;
    int vfunc_16();
};
int ParticleSystem::vfunc_16() {
    if (mValue)
        return DrawableContainer::vfunc_16() + 1;
    return DrawableContainer::vfunc_16();
}