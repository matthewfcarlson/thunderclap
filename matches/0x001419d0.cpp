extern "C" int __cdecl check(void*, void*, void*, void*, void*);
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
namespace hulkfight {
namespace motion {
class WallJumpTrack {};
} // namespace motion
} // namespace hulkfight
extern int a, b;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}