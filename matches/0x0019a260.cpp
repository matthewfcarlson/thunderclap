extern "C" int __cdecl CastHelper(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FireProjectileTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::Cast(void* p) {
    return CastHelper(p, 0, &a, &b, 0) != 0;
}
