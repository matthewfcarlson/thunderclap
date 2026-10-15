typedef unsigned int size_t;
void* __cdecl operator new(size_t);
extern "C" void _ReadWriteBarrier();
namespace hulkfight {
namespace ai {
class BaseTrack {
  public:
    virtual void f();
    char pad[8];
    BaseTrack() throw();
};
struct FacingData {
    int a;
    float b;
    int c;
    FacingData() throw() {
        a = 0;
        _ReadWriteBarrier();
        b = -1.0f;
        c = 0;
        _ReadWriteBarrier();
    }
};
class MotionFacingTrack : public BaseTrack, public FacingData {
  public:
    virtual void f();
    int d;
    int e;
    float g;
    float h;
    MotionFacingTrack() throw() {
        _ReadWriteBarrier();
        d = 0;
        e = 0;
        g = -1.0f;
        h = 1.0f;
    }
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
    virtual hulkfight::ai::MotionFacingTrack* vfunc_5();
};
class Factory : public TrackFactory {
  public:
    hulkfight::ai::MotionFacingTrack* vfunc_5();
};
hulkfight::ai::MotionFacingTrack* Factory::vfunc_5() {
    return new hulkfight::ai::MotionFacingTrack;
}
} // namespace fight