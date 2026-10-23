extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_0049850c;
extern int DAT_00499588;
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
class CGrappleInvulnerableTrack {};
template <> int fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499588, 0) != 0;
}