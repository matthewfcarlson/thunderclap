class CDropTrack;
extern int __cdecl check(CDropTrack*, int, void*, void*, int);
extern void* a;
extern void* b;
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
    return check(p, 0, &a, &b, 0) != 0;
}