typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int extra, a;
    BaseTrack() throw();
};
class Track : public BaseTrack {
  public:
    int b;
    float c;
    int d, e, f, g;
    Track() throw() : b(0), d(0), e(0), f(0), g(0) {}
};
class SuckTrack : public Track {
  public:
    SuckTrack() throw() : Track() {
        c = -1.0f;
        a = 1;
    }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual T* vfunc_5();
};
template <> hulkfight::motion::SuckTrack* TrackFactoryTemplate<hulkfight::motion::SuckTrack>::vfunc_5() {
    return new hulkfight::motion::SuckTrack;
}
} // namespace fight