extern "C" int __cdecl castLookup(void*, int, void*, void*, int);
extern int gA;
extern int gB;
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
class CGrappleInvulnerableTrack {};
template <> int fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_0(void* p) {
    return castLookup(p, 0, &gA, &gB, 0) != 0;
}