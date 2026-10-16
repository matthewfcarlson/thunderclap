namespace hulkfight {
namespace motion {
class MotionBlurTrack {};
} // namespace motion
} // namespace hulkfight
extern int __cdecl check(void*, int, void*, void*, int);
extern int a, b;
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
} // namespace fight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}