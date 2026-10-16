extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrappleAttachTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> int fight::TrackFactoryCasterTemplate<fight::CGrappleAttachTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}