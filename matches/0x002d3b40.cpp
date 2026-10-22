class Base {
  public:
    Base();
    virtual void fn();
    char pad[12];
    unsigned char flag;
    char gap[3];
    int a, b, c, d;
    char gap2[4];
    int e;
};
class ParticleGenerator_2d3b40 : public Base {
  public:
    ParticleGenerator_2d3b40() {
        flag = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
    }
};
struct Zeros {
    int f, g;
    Zeros() : f(0), g(0) {}
};
struct Floats {
    float h;
    int i;
    float j, k;
    Floats() : h(1.0f), i(0), j(1.0f), k(1.0f) {}
};
class ParticleSphereGenerator : public ParticleGenerator_2d3b40 {
  public:
    ParticleSphereGenerator();
    virtual void fn();
    Zeros z;
    char pad[4];
    Floats values;
};
ParticleSphereGenerator::ParticleSphereGenerator() {}