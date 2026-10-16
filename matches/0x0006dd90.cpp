class CHeadTrackerTrack;
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class HeadCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl cast(void*, int, void*, void*, int);
extern int a, b;
bool HeadCaster::vfunc_0(void* p) {
    return cast(p, 0, &a, &b, 0) != 0;
}