extern char DAT_0049850c[];
extern char DAT_004b3668[];
extern "C" void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
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
class HitPushbackTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_004b3668, 0) != 0;
}
