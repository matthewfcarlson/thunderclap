namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack {};
} // namespace motion
} // namespace hulkfight
extern void* g1;
extern void* g2;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}