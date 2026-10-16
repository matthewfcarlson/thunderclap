extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
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
class CivilianThrowTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}