extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_0049850c;
extern void* DAT_0049b198;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
class TrackFactoryCasterTemplate_CUninterruptibleTrack : public TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate_CUninterruptibleTrack::Cast(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b198, 0) != 0;
}