extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropActorThinkingTrack {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}