class TrackFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void* vfunc_5();
};
extern void* __cdecl operator_new(unsigned int);
class CGrappleInvincibleTrack {
  public:
    void Init();
};
void* TrackFactoryTemplate::vfunc_5() {
    CGrappleInvincibleTrack* p = (CGrappleInvincibleTrack*)operator_new(0x18);
    if (p) {
        p->Init();
        *(int*)p = 0x3fe828;
        return p;
    }
    goto fail;
fail:
    return 0;
}