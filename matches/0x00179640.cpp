extern int gTypeA;
extern int gTypeB;
extern "C" int __cdecl cast_check(void*, int, const void*, const void*, int);
namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack;
}
} // namespace hulkfight
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
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0(void* p) {
    return cast_check(p, 0, &gTypeA, &gTypeB, 0) != 0;
}
} // namespace fight