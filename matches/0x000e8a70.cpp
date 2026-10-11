extern "C" char DAT_0040bfe0[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class FEParticleSystem {
  public:
    char pad[0x28];
    Ref* volatile mRef;
    void Cleanup();
};
void FEParticleSystem::Cleanup() {
    *(volatile unsigned*)this = ((int)DAT_0040bfe0);
    Ref* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
}