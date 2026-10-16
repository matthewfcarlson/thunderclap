class Actor;
class Track;
extern int __cdecl Find(void*, int, void*, void*, int);
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
class PropActorToPropTrack {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_0(void* x) {
    return Find(x, 0, &a, &b, 0) != 0;
}