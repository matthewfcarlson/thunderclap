struct GrappleHoverTrack;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
extern void* gA;
extern void* gB;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <> int fight::TrackFactoryCasterTemplate<GrappleHoverTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &gB, 0) != 0;
}