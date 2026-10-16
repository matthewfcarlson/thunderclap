namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CHapticTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern int __cdecl check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}