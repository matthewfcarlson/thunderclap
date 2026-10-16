class GrappleAnimationTrack;
extern int __cdecl Check(GrappleAnimationTrack*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(GrappleAnimationTrack*);
    virtual void vfunc_1();
};
class Caster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(GrappleAnimationTrack*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::Caster::vfunc_0(GrappleAnimationTrack* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}