extern int __cdecl castfn(void*, int, const void*, const void*, int);
extern int a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void* p);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeLateralHBTrack {};
} // namespace ai
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_0(void* p) {
    return castfn(p, 0, &a, &b, 0) != 0;
}