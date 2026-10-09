class ParticleSphereGenerator {
  public:
    char pad[0x40];
    float value;
    float vfunc_8(int);
};
extern const float zero;
float ParticleSphereGenerator::vfunc_8(int arg) {
    if (arg != 6)
        return zero;
    return value;
}