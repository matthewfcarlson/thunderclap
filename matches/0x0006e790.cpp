extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
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
    return Check(p, 0, &gA, &gB, 0) != 0;
}