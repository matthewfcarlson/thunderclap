class Base {
  public:
    virtual void f();
    char pad[8];
    int a, b;
    Base();
};
class CSmartPropSetStateTrack : public Base {
  public:
    virtual void f();
    CSmartPropSetStateTrack();
};
CSmartPropSetStateTrack::CSmartPropSetStateTrack() {
    a = 0;
    b = 0;
}