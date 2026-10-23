class Track {};
extern int __cdecl FUN_00344e74(Track*, int, void*, void*, int);
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
extern int DAT_0049850c, DAT_004af890;
bool fight::CivilianCaster::vfunc_0(Track* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af890, 0) != 0;
}