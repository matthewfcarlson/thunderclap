extern int FUN_00344e74(void*, int, int, int, int);
extern int g_49850c;
extern int g_4acbf8;
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
int TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return (int)FUN_00344e74(p, 0, (int)&g_4acbf8, (int)&g_49850c, 0) != 0;
}
