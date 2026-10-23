namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
class CSoundTrack {};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c, DAT_0049aef8;
template <> int fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049aef8, 0) != 0;
}