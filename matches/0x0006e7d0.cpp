class CWallSlideTrack;
extern int __cdecl Factory(CWallSlideTrack*, int, void*, void*, int);
extern int a, b;
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
    return Factory(p, 0, &a, &b, 0) != 0;
}
} // namespace fight