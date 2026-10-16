int __cdecl Find(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern int a, b;
bool fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return Find(p, 0, &a, &b, 0) != 0;
}