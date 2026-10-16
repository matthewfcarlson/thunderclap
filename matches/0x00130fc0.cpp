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
class NISSoundTrack;
}
extern int g1, g2;
extern "C" int __cdecl cast(void*, int, int*, int*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>::vfunc_0(void* p) {
    return cast(p, 0, &g1, &g2, 0) != 0;
}