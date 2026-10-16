extern int a;
extern int b;
extern "C" void* __cdecl findThing(void*, int, void*, void*, int);
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
namespace motion {
class PushOutTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_0(void* p) {
    return findThing(p, 0, &a, &b, 0) != 0;
}