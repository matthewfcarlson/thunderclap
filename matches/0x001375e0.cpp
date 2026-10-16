extern const void* a;
extern const void* b;
extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool check(void*) = 0;
    virtual void other() = 0;
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool check(void*);
    virtual void other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingBrakeTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingBrakeTrack>::check(void* p) {
    return cast(p, 0, &a, &b, 0) != 0;
}