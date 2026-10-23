struct TypeInfo {
    int x;
};
extern TypeInfo DAT_0049850c, DAT_0049a650;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
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
class CPushBackAnimationTrack {};
template <> int TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a650, 0) != 0;
}
} // namespace fight