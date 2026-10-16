extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char a, b;
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
class CClearHitRecordsTrack {};
template <> bool fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}