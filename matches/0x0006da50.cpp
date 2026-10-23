extern int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
extern int DAT_0049850c, DAT_004993c0;
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
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004993c0, 0) != 0;
}