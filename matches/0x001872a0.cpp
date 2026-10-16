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
class BallAndChainSpinTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0(void* p) {
    return helper(p, 0, &g1, &g2, 0) != 0;
}