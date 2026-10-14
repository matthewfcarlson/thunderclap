class ParticleSphereGenerator {
  public:
    char pad[0x40];
    float value;
    float vfunc_8(int);
};
extern const float zero_2d2fa0;
float ParticleSphereGenerator::vfunc_8(int arg) {
    if (arg != 6)
        return zero_2d2fa0;
    return value;
}