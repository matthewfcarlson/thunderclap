class CInvulnerableTrack;
extern int __cdecl FindTrack(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <> int TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_0(void* p) {
    return FindTrack(p, 0, &a, &b, 0) != 0;
}
} // namespace fight