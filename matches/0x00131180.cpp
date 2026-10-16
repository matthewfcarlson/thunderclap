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
class StatEndTrialTrack {};
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}