extern "C" int __cdecl Check(void*, int, void*, void*, int);
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
class CGrappleSequenceTrack {};
template <> int fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}