extern "C" int __cdecl cast(void*, int, const void*, const void*, int);
extern char typeSource;
extern char typeDestination;
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
class SuckTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>::vfunc_0(void* p) {
    return cast(p, 0, &typeSource, &typeDestination, 0) != 0;
}