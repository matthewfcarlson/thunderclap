extern "C" int __cdecl Search(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
class CivilianAttachTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_0(void* p) {
    return Search(p, 0, &a, &b, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>;