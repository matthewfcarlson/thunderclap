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
namespace scenario {
class EffectTrack {};
} // namespace scenario
} // namespace hulkfight
extern int A;
extern int B;
extern "C" int __cdecl FUN_00344e74(void*, int, int*, int*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::EffectTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &A, &B, 0) != 0;
}