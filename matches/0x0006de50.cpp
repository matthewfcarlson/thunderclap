extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct CIntangibleTrack;
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
int TrackFactoryCasterTemplate::vfunc_0(void* a) {
    return (FUN_00344e74(a, 0, (void*)0x49850c, (void*)0x499d20, 0) != 0);
}
