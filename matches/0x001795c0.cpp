extern char gA, gB;
extern "C" void* __cdecl Find(void*, void*, void*, void*, void*);
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
class TeleportTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_0(void* p) {
    return Find(p, 0, &gA, &gB, 0) != 0;
}
