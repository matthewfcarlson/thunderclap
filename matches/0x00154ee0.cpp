namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitDamageTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char a, b;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &b, 0) != 0;
}