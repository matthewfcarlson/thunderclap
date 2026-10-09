int g_vt = 0;

class Ref {
  public:
    virtual void vfunc0();
    virtual void Release();
};

extern "C" void __cdecl FUN_00267090(void*);

class ParticleSystem {
  public:
    char pad[0xa4];
    Ref* volatile a;
    Ref* volatile b;
    void Cleanup();
    ParticleSystem* vfunc_2(unsigned char p);
};

ParticleSystem* ParticleSystem::vfunc_2(unsigned char p) {
    volatile int* q = (volatile int*)this;
    *q = (int)&g_vt;
    Ref* x = a;
    if (x) {
        x->Release();
        a = 0;
    }
    Ref* y = b;
    if (y) {
        y->Release();
        b = 0;
    }
    Cleanup();
    if (p & 1) {
        FUN_00267090(this);
    }
    return this;
}
