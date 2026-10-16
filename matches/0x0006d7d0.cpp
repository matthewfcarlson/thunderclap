extern "C" int __cdecl lookup(void*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CEffectTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return lookup(p, 0, &a, &b, 0) != 0;
}