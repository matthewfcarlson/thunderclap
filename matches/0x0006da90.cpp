extern "C" int __cdecl check(void*, int, const void*, const void*, int);
extern int a, b;
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
class CGrappleIntangibleTrack {};
template <> bool fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}