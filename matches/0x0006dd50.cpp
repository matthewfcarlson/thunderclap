class CGrappleUninterruptibleTrack;
int __cdecl Cast(void*, int, void*, void*, int);
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
extern void* a;
extern void* b;
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return Cast(p, 0, &a, &b, 0) != 0;
}