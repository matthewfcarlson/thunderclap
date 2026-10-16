extern int __cdecl check(void*, int, void*, void*, int);
extern int g1, g2;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CWeaponCollisionTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return check(p, 0, &g1, &g2, 0) != 0;
}