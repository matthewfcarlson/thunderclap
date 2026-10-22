class TrackFactoryCasterTemplate_72c40 {
  public:
    virtual void cast();
};
struct CDamageTrack;
extern void __cdecl Find(CDamageTrack*, TrackFactoryCasterTemplate_72c40*);
void __cdecl Target(CDamageTrack* track) {
    TrackFactoryCasterTemplate_72c40 c;
    Find(track, &c);
}