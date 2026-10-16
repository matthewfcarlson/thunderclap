struct A {};
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;
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
    return check(p, 0, &g1, &g2, 0) != 0;
}
} // namespace fight