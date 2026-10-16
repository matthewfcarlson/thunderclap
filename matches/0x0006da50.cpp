extern int __cdecl Check(void*, void*, void*, void*, void*);
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
} // namespace fight
class CGrappleEffectStopTrack {};
template <> int fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}