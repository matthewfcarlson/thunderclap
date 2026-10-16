typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
};
class CGrappleUninterruptibleTrack : public BaseTrack {
  public:
    CGrappleUninterruptibleTrack() throw() : BaseTrack() {}
    virtual void v0();
    char padding[0x14];
};
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
    return new CGrappleUninterruptibleTrack;
}