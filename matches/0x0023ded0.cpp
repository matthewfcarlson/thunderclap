typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
class Track {
  public:
    Track() throw();
    virtual void f0();
    char pad[4];
    int a;
    int b;
};
class CommentTrack : public Track {
  public:
    CommentTrack() throw();
    virtual void f0();
};
class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Track* vfunc_5();
};
Track* TrackFactoryTemplate::vfunc_5() {
    return new CommentTrack;
}
CommentTrack::CommentTrack() throw() : Track() {
    b = 0;
    a = 1;
}
} // namespace fight