extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrabTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <> bool TrackFactoryCasterTemplate<CGrabTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x498fc4, 0) != 0;
}
} // namespace fight