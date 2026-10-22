class CTrack_62740 {
  public:
    virtual void f();
    char pad[8];
    int a, b;
    CTrack_62740();
};
class CSmartPropSetStateTrack : public CTrack_62740 {
  public:
    virtual void f();
    CSmartPropSetStateTrack();
};
CSmartPropSetStateTrack::CSmartPropSetStateTrack() {
    a = 0;
    b = 0;
}