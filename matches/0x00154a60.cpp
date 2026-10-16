typedef unsigned int size_t;
extern "C" void* __cdecl dynamic_cast_helper(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitPauseTrack {};
} // namespace motion
} // namespace hulkfight
extern char typeA, typeB;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0(void* p) {
    return dynamic_cast_helper(p, 0, &typeA, &typeB, 0) != 0;
}