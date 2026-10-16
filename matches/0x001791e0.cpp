extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char sourceType;
extern char targetType;
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
class MoveJointTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_0(void* p) {
    return __RTDynamicCast(p, 0, &sourceType, &targetType, 0) != 0;
}