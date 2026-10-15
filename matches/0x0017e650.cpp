typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace fight {
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
} // namespace fight
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void f();
    char pad[4];
    int one;
    int zero;
};
namespace hulkfight {
namespace motion {
class TargetBreakTrack : public BaseTrack {
  public:
    TargetBreakTrack() throw();
    virtual void f();
};
} // namespace motion
} // namespace hulkfight
hulkfight::motion::TargetBreakTrack::TargetBreakTrack() throw() : BaseTrack() {
    zero = 0;
    one = 1;
}
void* fight::TrackFactory::vfunc_5() {
    return new hulkfight::motion::TargetBreakTrack;
}