extern "C" int match(void*, int, void*, void*, int);
extern int gA, gB;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplateCSmartPropEventTrack : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplateCSmartPropEventTrack::vfunc_0(void* p) {
    return match(p, 0, &gA, &gB, 0) != 0;
}