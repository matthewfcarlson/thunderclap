class CGrappleSoundTrack;
extern "C" int __cdecl Query(void*, int, int, int, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
extern int a, b;
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_0(void* p) {
    return Query(p, 0, (int)&a, (int)&b, 0) != 0;
}