extern int a, b;
extern "C" int __cdecl check(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CAutoTargetTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <> int TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight