extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
class PropAddToCollisionTrack;
}
} // namespace hulkfight
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}