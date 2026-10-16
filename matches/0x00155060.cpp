extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;
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
class NoHitPushbackTrack {};
} // namespace motion
} // namespace hulkfight
int fight::TrackFactoryCasterTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}
