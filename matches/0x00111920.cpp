extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
class ButtonTrack {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0(void* p) {
    return Find(p, 0, &a, &b, 0) != 0;
}