// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::ParticleSystem::vfunc_17 @ 0x002a37b0
namespace pure3d {
struct DrawableContainer {
    void vfunc_17(int, int);
};
struct ParticleEntry {
    char padding[8];
    int first;
    int second;
};
struct ParticleSystem : DrawableContainer {
    char padding[0xa4 - sizeof(DrawableContainer)];
    ParticleEntry* current;
    void vfunc_17(int first, int second);
};
void ParticleSystem::vfunc_17(int first, int second) {
    if (!current || current->first != first || current->second != second)
        DrawableContainer::vfunc_17(first, second);
}
}