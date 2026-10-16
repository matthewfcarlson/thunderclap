namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl doCast(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingAttackTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_0(void* p) {
    return doCast(p, 0, &gA, &gB, 0) != 0;
}