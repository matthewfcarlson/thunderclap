extern int DAT_0049850c, DAT_0049a49c;
extern "C" int __cdecl FUN_00344e74(const char*, int, const int*, const int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class COrientTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <> bool TrackFactoryCasterTemplate<COrientTrack>::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a49c, 0) != 0;
}
} // namespace fight