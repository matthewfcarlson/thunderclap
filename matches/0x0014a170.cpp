class Track {};
extern int __cdecl Cast(Track*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(Track*);
    virtual void vfunc_1();
};
class CivilianCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(Track*);
    virtual void vfunc_1();
};
} // namespace fight
extern int gA, gB;
bool fight::CivilianCaster::vfunc_0(Track* p) {
    return Cast(p, 0, &gA, &gB, 0) != 0;
}