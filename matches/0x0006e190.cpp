extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a;
extern int b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
class TrackFactoryCasterTemplate_COpportunityBallTrack : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate_COpportunityBallTrack::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}