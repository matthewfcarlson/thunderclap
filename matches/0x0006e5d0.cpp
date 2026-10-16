extern "C" int __cdecl Check(void*, int, const void*, const void*, int);
extern int a, b;
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
bool TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight