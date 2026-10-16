class CMoveTrack;
extern int __cdecl Check(CMoveTrack*, int, void*, void*, int);
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
extern void* gA;
extern void* gB;
int fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_0(void* p) {
    return Check((CMoveTrack*)p, 0, &gA, &gB, 0) != 0;
}
