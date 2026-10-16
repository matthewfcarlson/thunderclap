extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class PropCaster : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int PropCaster::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight