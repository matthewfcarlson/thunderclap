class Base {
  public:
    Base();
    virtual void f();
    char fields[8];
};
class Member {
  public:
    Member();
};
class PostEvent_StringTrack : public Base {
  public:
    PostEvent_StringTrack();
    virtual void f();
    int n;
    Member member;
    char pad[7];
    char a, b;
};
PostEvent_StringTrack::PostEvent_StringTrack() : Base(), n(0), member(), a(0), b(0) {}