class CMoveTrack;
extern int __cdecl FUN_00344e74(CMoveTrack*, int, void*, void*, int);
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
extern void* DAT_0049850c;
extern void* DAT_0049a278;
template <> int fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_0(void* p) {
    return FUN_00344e74((CMoveTrack*)p, 0, &DAT_0049850c, &DAT_0049a278, 0) != 0;
}
