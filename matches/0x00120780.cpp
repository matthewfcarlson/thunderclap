namespace hulkfight {
namespace ai {
class PathFormationTrack;
}
} // namespace hulkfight
int __cdecl CastFunc(void*, int, void*, void*, int);
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
template <> int TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_0(void* p) {
    return CastFunc(p, 0, (void*)0x49850c, (void*)0x4a66d8, 0) != 0;
}
} // namespace fight