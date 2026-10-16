extern int gType1;
extern int gType2;
extern "C" int __cdecl castCheck(void*, int, void*, void*, int);
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
class PropAnimationTrack {};
} // namespace motion
} // namespace hulkfight
int fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAnimationTrack>::vfunc_0(void* p) {
    return castCheck(p, 0, &gType1, &gType2, 0) != 0;
}
