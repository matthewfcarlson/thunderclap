extern int __cdecl Lookup(void*, int, void*, void*, int);
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
class FireMissileTrack {};
} // namespace motion
} // namespace hulkfight
extern int g1, g2;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_0(void* p) {
    return Lookup(p, 0, &g1, &g2, 0) != 0;
}