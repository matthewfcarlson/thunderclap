extern "C" int __cdecl check(void*, int, void*, void*, int);
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
class LocomotionStrafe4Track;
}
} // namespace hulkfight
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}