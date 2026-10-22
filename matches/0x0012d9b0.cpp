class Track_12d9b0 {
  public:
    Track_12d9b0();
    virtual void f();
    char fields[8];
};
class Member {
  public:
    Member();
};
class PostEvent_StringTrack : public Track_12d9b0 {
  public:
    PostEvent_StringTrack();
    virtual void f();
    int n;
    Member member;
    char pad[7];
    char a, b;
};
PostEvent_StringTrack::PostEvent_StringTrack() : Track_12d9b0(), n(0), member(), a(0), b(0) {}