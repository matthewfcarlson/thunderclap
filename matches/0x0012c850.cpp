class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ThreatDodgeTrack;
extern "C" int FUN_00344e74(void*, void*, void*, void*, void*);
extern int a, b;
class Caster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}