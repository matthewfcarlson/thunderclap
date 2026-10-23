class CSmartPropThrowingTrack;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
bool TrackFactoryCasterTemplate::Cast(void* p) {
    return FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x49ad40, 0) != 0;
}
} // namespace fight