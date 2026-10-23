extern "C" void* DAT_0049850c;
extern "C" void* DAT_004ba610;
extern "C" void* __cdecl FUN_00344e74(void*, int, void**, void**, int);
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
class TargetBreakTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_0(void* obj) {
    return FUN_00344e74(obj, 0, &DAT_0049850c, &DAT_004ba610, 0) != 0;
}
