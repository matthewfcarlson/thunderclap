class Track;
extern "C" int __cdecl Find(void*, int, void*, void*, void*);
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
class FlyingAutoTargetTrack {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0(void* p) {
    return Find(p, 0, &a, &b, 0) != 0;
}