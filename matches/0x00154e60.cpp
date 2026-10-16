extern char gA, gB;
extern "C" int __cdecl DoCast(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class HealthCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::HealthCaster::vfunc_0(void* p) {
    return DoCast(p, 0, &gA, &gB, 0) != 0;
}