extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
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
class DialogueTrack {};
} // namespace hulkfight
bool fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
