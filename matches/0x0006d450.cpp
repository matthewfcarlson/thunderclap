extern int gA, gB;
extern "C" int __cdecl Cast(void*, int, const void*, const void*, int);
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
int TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return Cast(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight