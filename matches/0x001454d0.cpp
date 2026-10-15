extern "C" int __cdecl FUN_00344e74(int, int, void*, void*, int);

class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int);
    virtual void vfunc_1();
};

class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int);
};

bool TrackFactoryCasterTemplate::vfunc_0(int arg) {
    return (FUN_00344e74(arg, 0, (void*)0x49850c, (void*)0x4ae250, 0) != 0);
}
