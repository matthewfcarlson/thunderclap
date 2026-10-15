typedef unsigned int size_t;
void* operator new(size_t);
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int x;
    int flag;
};
class CInvulnerableTrack : public BaseTrack {
  public:
    CInvulnerableTrack() throw();
    virtual void f0();
    int a;
    float b;
    int c;
};
CInvulnerableTrack::CInvulnerableTrack() throw() {
    a = 0;
    b = -1.0f;
    c = 0;
    flag = 1;
}
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BaseTrack* vfunc_5();
};
BaseTrack* Factory::vfunc_5() {
    return new CInvulnerableTrack;
}