struct Block {
    int a[16];
};
namespace pure3d {
class ParticleEmitter {
    char pad[0x40];
    Block b;

  public:
    Block vfunc_22();
};
Block ParticleEmitter::vfunc_22() {
    return b;
}
} // namespace pure3d