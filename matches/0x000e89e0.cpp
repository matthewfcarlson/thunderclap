class Ref {
  public:
    virtual void f();
    virtual void g();
};
class Mid {
  public:
    void Done();
};
class FEParticleAnimation {
  public:
    virtual void a();
    char pad[0x64 - 4];
    Ref* volatile mRef;
    void Cleanup();
};
void FEParticleAnimation::Cleanup() {
    *(int* volatile*)this = (int*)0x40c3d0;
    Ref* r = mRef;
    if (r) {
        r->g();
        mRef = 0;
    }
    ((Mid*)this)->Done();
}
