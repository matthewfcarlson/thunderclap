extern "C" int __cdecl testCast(void*, int, void*, void*, int);
extern int gA, gB;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
class CMotionHitGroundHeightTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::Cast(void* p) {
    return testCast(p, 0, &gA, &gB, 0) != 0;
}