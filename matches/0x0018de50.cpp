namespace hulkfight {
namespace motion {
class VarAssignTrack {};
} // namespace motion
} // namespace hulkfight
struct TypeRecord {
    void* vtable;
};
extern const TypeRecord varAssignType;
extern const TypeRecord baseTrackType;
extern "C" int __cdecl TrackCast(void*, int, const TypeRecord*, const TypeRecord*, int);
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
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::VarAssignTrack>::vfunc_0(void* track) {
    return TrackCast(track, 0, &baseTrackType, &varAssignType, 0) != 0;
}