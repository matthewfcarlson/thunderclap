namespace hulkfight {
class XPTrack;
}
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
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
template <> int TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
} // namespace fight