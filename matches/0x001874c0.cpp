extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern int a;
extern int b;
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
class PropDamageTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}