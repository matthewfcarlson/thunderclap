int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char* s);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char* s);
};
bool TrackFactoryCasterTemplate::vfunc_0(const char* s) {
    int r = FUN_00344e74(s, 0, (const char*)0x49850c, (const char*)0x4a46a8, 0);
    return r != 0;
}
