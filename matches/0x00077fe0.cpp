extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class CTrack_77fe0 : public Base {
  public:
    CTrack_77fe0() : a(0), b(0) {}
    int a, b;
};
class CExplosionTrack : public CTrack_77fe0 {
  public:
    CExplosionTrack();
    int c, d, e;
    virtual void g() {}
};
CExplosionTrack::CExplosionTrack() : CTrack_77fe0() {
    _ReadWriteBarrier();
    c = 0;
    d = 0;
    e = 0;
}