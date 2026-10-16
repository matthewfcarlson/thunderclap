class CStunAnimationTrack;
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
template <> int fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}