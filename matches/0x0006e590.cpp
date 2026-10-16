class CSmartPropThrowingTrack;
extern "C" void* __cdecl FindTrack(void*, int, void*, void*, int);
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
    return FindTrack(p, 0, (void*)0x49850c, (void*)0x49ad40, 0) != 0;
}
} // namespace fight