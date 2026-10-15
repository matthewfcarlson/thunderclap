class Obj {};
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(Obj*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(Obj*);
};
int __cdecl FUN_00344e74(Obj*, int, void*, void*, int);
bool TrackFactoryCasterTemplate::vfunc_0(Obj* p) {
    return (int)FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x4abba8, 0) != 0;
}
