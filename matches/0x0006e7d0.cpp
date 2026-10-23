class CWallSlideTrack;
extern int __cdecl FUN_00344e74(CWallSlideTrack*, int, void*, void*, int);
extern int DAT_0049850c, DAT_0049b224;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(CWallSlideTrack*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(CWallSlideTrack*);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(CWallSlideTrack* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b224, 0) != 0;
}
} // namespace fight