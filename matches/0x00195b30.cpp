extern "C" char DAT_0041b3f4[];
class Base {
  public:
    virtual void V0();
    virtual void V1();
};
class Helper {
  public:
    void Use(void*);
};
extern Helper* FUN_0027f250();
class ProjectileEffect {
  public:
    void* vptr;
    char pad04[0x14];
    void* m18;
    void* m1c;
    char pad20[4];
    Base* m24;
    void Finish();
    void Cleanup();
};
void ProjectileEffect::Cleanup() {
    *(void**)this = (void*)((int)DAT_0041b3f4);
    if (m1c) {
        Helper* x = FUN_0027f250();
        x->Use(m1c);
    }
    if (m24) {
        m24->V1();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Finish();
}