extern int gA, gB;
extern "C" int __cdecl Lookup(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SlowMotionTrack;
}
} // namespace hulkfight
int fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_0(void* p) {
    return Lookup(p, 0, &gA, &gB, 0) != 0;
}
