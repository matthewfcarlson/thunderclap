class ParticleGenerator {
  public:
    void* vftable;
    char pad4[0x0c];
    unsigned char a;
    char pad11[3];
    int b, c, d, e;
    void Init();
};
ParticleGenerator* __fastcall FUN_002d2070(ParticleGenerator* p) {
    p->Init();
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->vftable = (void*)0x42f074;
    return p;
}