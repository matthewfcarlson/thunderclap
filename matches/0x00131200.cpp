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
class StatTrack {};
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}