class CJumpAttackTrack;
extern int __cdecl TryCast(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return TryCast(p, 0, (void*)0x49850c, (void*)0x49a050, 0) != 0;
}
} // namespace fight