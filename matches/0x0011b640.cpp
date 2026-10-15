typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[8];
};
namespace hulkfight {
namespace ai {
class MotionChaseTrack : public BaseTrack {
  public:
    virtual void v0();
    int a;
    float b;
    int c, d, e, f;
    float g;
    int h;
    MotionChaseTrack() throw() : a(0), b(-1.0f), c(0), d(0), e(0), f(0), g(1.0f), h(0) {}
};
} // namespace ai
} // namespace hulkfight
namespace fight {
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};
template <class T> class TrackFactoryTemplate : public TrackFactory {
  public:
    virtual void* v5();
};
} // namespace fight
template <class T> void* fight::TrackFactoryTemplate<T>::v5() {
    return new T;
}
template void* fight::TrackFactoryTemplate<hulkfight::ai::MotionChaseTrack>::v5();