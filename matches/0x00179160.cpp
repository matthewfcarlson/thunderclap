namespace hulkfight {
namespace motion {
class LocomotionStateTrack;
}
} // namespace hulkfight
extern int gTypeA;
extern int gTypeB;
extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <> int TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_0(void* p) {
    return CastCheck(p, 0, &gTypeA, &gTypeB, 0) != 0;
}
} // namespace fight