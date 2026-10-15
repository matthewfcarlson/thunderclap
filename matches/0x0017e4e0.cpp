typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void f0();
    char pad[8];
};
class MotionStateTrack : public BaseTrack {
  public:
    MotionStateTrack() throw() : BaseTrack(), b(0), c(-1.0f), d(0) { *(int*)(pad + 4) = 1; }
    virtual void f0();
    int b;
    float c;
    int d;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual hulkfight::motion::MotionStateTrack* vfunc_5();
};
class Factory : public TrackFactory {
  public:
    hulkfight::motion::MotionStateTrack* vfunc_5();
};
hulkfight::motion::MotionStateTrack* Factory::vfunc_5() {
    return new hulkfight::motion::MotionStateTrack;
}
} // namespace fight