extern int gTypeA;
extern int gTypeB;
extern "C" void* __cdecl CastTrack(void*, int, const void*, const void*, int);
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
class VisibilityTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_0(void* p) {
    return CastTrack(p, 0, &gTypeA, &gTypeB, 0) != 0;
}