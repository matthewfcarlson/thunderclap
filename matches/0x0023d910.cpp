class Track {
  public:
    Track();
    virtual void f();
    char pad[4];
};
class CommentTrack : public Track {
  public:
    CommentTrack();
    virtual void f();
    int a;
    int b;
};
CommentTrack::CommentTrack() : Track() {
    b = 0;
    a = 1;
}