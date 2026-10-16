namespace hulkfight {
namespace motion {
class MomentumXZAddTrack;
}
} // namespace hulkfight
extern int firstType;
extern int secondType;
extern "C" void* __cdecl castTrack(void*, int, const void*, const void*, int);
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
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_0(void* p) {
    return castTrack(p, 0, &firstType, &secondType, 0) != 0;
}
} // namespace fight