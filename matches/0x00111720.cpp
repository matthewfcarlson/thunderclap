extern int gOne;
extern int gTwo;
extern "C" int __cdecl factoryCheck(void*, int, int*, int*, int);
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
namespace ai {
class TokenSupressTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0(void* p) {
    return factoryCheck(p, 0, &gOne, &gTwo, 0) != 0;
}
