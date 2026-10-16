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
class HitThrowTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a;
extern int b;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}