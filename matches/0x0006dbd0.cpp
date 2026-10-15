extern int FUN_00344e74(void* a, int b, void* c, void* d, int e);
extern char CGrappleMotionTrailTrack[];
extern char CGrappleMotionTrailTrackEnd[];
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* a) {
    return (int)FUN_00344e74(a, 0, CGrappleMotionTrailTrack, CGrappleMotionTrailTrackEnd, 0) != 0;
}
