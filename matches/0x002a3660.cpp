extern "C" char DAT_0042d88c[];
void* __stdcall FUN_002a4e10(void*);
void FUN_0022b980();
struct Sub_2a3660 {
    void Init();
};
class ParticleSystem {
  public:
    unsigned int vt;
    char p[0x54];
    unsigned char flag;
    char p2[3];
    float x;
    float y;
    Sub_2a3660 sub;
    char p3[0x3c];
    int a;
    int b;
    ParticleSystem* Build(void* arg);
};
ParticleSystem* ParticleSystem::Build(void* arg) {
    FUN_002a4e10(arg);
    vt = ((int)DAT_0042d88c);
    flag = 1;
    x = 100.0f;
    y = 30.0f;
    a = 0;
    b = 0;
    sub.Init();
    return this;
}