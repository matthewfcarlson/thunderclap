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
namespace ai {
class RoutTrack {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern int a, b;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::RoutTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}