typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    int base;
};
class LocomotingTrack : public BaseTrack {
  public:
    LocomotingTrack() throw() : BaseTrack() {
        zero = 0;
        neg = -1.0f;
        flag = 1;
    }
    virtual void v0();
    int flag;
    int zero;
    float neg;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};
template <class T> class TrackFactoryTemplate : public TrackFactory {
  public:
    virtual void* vfunc_5();
};
template <class T> void* TrackFactoryTemplate<T>::vfunc_5() {
    return new T;
}
template void* TrackFactoryTemplate<hulkfight::motion::LocomotingTrack>::vfunc_5();
} // namespace fight