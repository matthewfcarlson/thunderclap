class CDropTrack;
extern int __cdecl FUN_00344e74(CDropTrack*, int, void*, void*, int);
extern void* DAT_0049850c;
extern void* DAT_00498dbc;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(CDropTrack*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(CDropTrack*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::vfunc_0(CDropTrack* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498dbc, 0) != 0;
}