struct Info {};
extern Info a, b;
extern "C" int __cdecl check(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int cast(void*);
    virtual void other();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int cast(void*);
    virtual void other();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeCircleTrack {};
} // namespace ai
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleTrack>::cast(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}