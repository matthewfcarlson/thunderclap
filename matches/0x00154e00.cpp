extern int __cdecl check(void*, int, void*, void*, int);
extern int g1, g2;
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
class HitPushbackAddTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_0(void* p) {
    return check(p, 0, &g1, &g2, 0) != 0;
}