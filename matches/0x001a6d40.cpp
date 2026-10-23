extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
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
namespace scenario {
class NISAnimationTrack {};
} // namespace scenario
} // namespace hulkfight
extern void* DAT_0049850c;
extern void* DAT_004c2650;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c2650, 0) != 0;
}