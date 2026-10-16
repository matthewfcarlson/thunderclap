struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl match(void*, int, TypeInfo*, TypeInfo*, int);
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
class FlyingDashTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_0(void* p) {
    return match(p, 0, &a, &b, 0) != 0;
}