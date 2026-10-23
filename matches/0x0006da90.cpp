extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern int DAT_0049850c, DAT_00499458;
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
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499458, 0) != 0;
}