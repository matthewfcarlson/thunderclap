struct CMoveAddTrack;
extern int __cdecl castfn(void*, int, void*, void*, int);
extern int a, b;
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
template <> int TrackFactoryCasterTemplate<CMoveAddTrack>::vfunc_0(void* p) {
    return castfn(p, 0, &a, &b, 0) != 0;
}
} // namespace fight