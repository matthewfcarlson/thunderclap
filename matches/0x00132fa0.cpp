typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[8];
};
class XPTrack : public BaseTrack {
  public:
    XPTrack() throw();
    virtual void v0();
    int a, b;
};
XPTrack::XPTrack() throw() : BaseTrack(), a(0), b(0) {}
} // namespace hulkfight
namespace fight {
class TrackFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::XPTrack* vfunc_5();
};
hulkfight::XPTrack* TrackFactoryTemplate::vfunc_5() {
    return new hulkfight::XPTrack;
}
} // namespace fight