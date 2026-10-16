struct TypeInfo {
    int x;
};
extern TypeInfo srcType, dstType;
extern "C" void* __cdecl Cast(void*, int, TypeInfo*, TypeInfo*, int);
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
    return Cast(p, 0, &srcType, &dstType, 0) != 0;
}
} // namespace fight