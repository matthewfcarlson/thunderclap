class ParticlePointGenerator {
public:
    char pad[0x44]; int a; int b; int c;
    void vfunc_7(int x, int y);
};
void ParticlePointGenerator::vfunc_7(int x, int y) {
    switch (x) {
    case 1: a = y; break;
    case 2: b = y; break;
    case 3: c = y; break;
    }
}
