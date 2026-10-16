extern "C" int __cdecl Check(void*, int, void*, void*, int);
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
class PropAddToMissileCountTrack {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}