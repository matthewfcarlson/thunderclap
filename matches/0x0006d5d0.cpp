extern int __cdecl Check(void*, int, const void*, const void*, int);
extern int a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CCollisionTrack {};
template <> int fight::TrackFactoryCasterTemplate<CCollisionTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}