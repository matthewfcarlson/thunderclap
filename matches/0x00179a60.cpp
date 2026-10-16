extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
extern "C" char sourceType, targetType;
namespace hulkfight {
namespace motion {
class ChargeClearTrack;
}
} // namespace hulkfight
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
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0(void* object) {
    return cast(object, 0, &sourceType, &targetType, 0) != 0;
}
} // namespace fight