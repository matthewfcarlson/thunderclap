class CTargetTrack {};
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
extern int FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}