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
class TargetIconDistanceTrack;
}
} // namespace hulkfight
extern int typeA;
extern int typeB;
extern "C" void* castTrack(void*, void*, void*, void*, void*);
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0(void* p) {
    return castTrack(p, 0, &typeA, &typeB, 0) != 0;
}