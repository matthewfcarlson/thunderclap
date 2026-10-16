extern "C" int __cdecl TestCaster(void*, int, void*, void*, int);
extern int gA;
extern int gB;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CSmartPropDetachTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return TestCaster(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight