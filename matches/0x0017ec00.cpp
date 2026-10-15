typedef unsigned int size_t;
void* operator new(size_t) throw();
extern "C" void _ReadWriteBarrier();
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[4];
    int ref;
};
class MidTrack : public BaseTrack {
  public:
    MidTrack() throw() : a(0), b(0) {}
    int a, b;
};
struct Values {
    Values() throw() {
        _ReadWriteBarrier();
        c = 0;
        d = 0;
        f = -1.0f;
    }
    int c, d;
    float f;
};
class TeleportToLocatorTrack : public MidTrack {
  public:
    TeleportToLocatorTrack() throw() { ref = 1; }
    virtual void v0();
    Values v;
};
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BaseTrack* vfunc_5();
};
class TeleportFactory : public TrackFactory {
  public:
    virtual BaseTrack* vfunc_5();
};
BaseTrack* TeleportFactory::vfunc_5() {
    return new TeleportToLocatorTrack;
}