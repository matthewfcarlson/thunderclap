extern int DAT_0049850c, DAT_0049a520;
extern "C" void* __cdecl FUN_00344e74(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class COrientTargetTrack {};
template <> bool fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a520, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<COrientTargetTrack>;
