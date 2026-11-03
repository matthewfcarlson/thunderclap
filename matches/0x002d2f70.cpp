class ParticleSphereGenerator {
  public:
    char pad[0x48];
    void vfunc_7(int, unsigned);
};
void ParticleSphereGenerator::vfunc_7(int which, unsigned value) {
    switch (which) {
    case 3:
        *(unsigned*)(pad + 0x44) = value;
        break;
    case 6:
        *(unsigned*)(pad + 0x40) = value;
        break;
    }
}