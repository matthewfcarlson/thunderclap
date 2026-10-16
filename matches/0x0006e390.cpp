class CSmartPropAttachTrack;
extern void* gA;
extern void* gB;
extern "C" int Find(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return Find(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight