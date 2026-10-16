extern "C" int __cdecl check(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FallTrack {};
} // namespace motion
} // namespace hulkfight
extern int a, b;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FallTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}