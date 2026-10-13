extern void* g_vftable[];
class TrackFactoryCasterTemplate {
  public:
    virtual void A();
};
class CComboTimerTrack : public TrackFactoryCasterTemplate {
  public:
    virtual void A();
    CComboTimerTrack();
};
CComboTimerTrack::CComboTimerTrack() {}
