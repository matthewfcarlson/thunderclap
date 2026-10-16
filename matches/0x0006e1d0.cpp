extern int gA, gB;
extern "C" int __cdecl Find(const char*, int, const int*, const int*, int);
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
    return Find(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight