extern "C" void* gTypeA;
extern "C" void* gTypeB;
extern "C" void* __cdecl Check(void*, int, void**, void**, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetBreakTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_0(void* obj) {
    return Check(obj, 0, &gTypeA, &gTypeB, 0) != 0;
}
