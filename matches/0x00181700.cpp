class Track_181700 {
  public:
    Track_181700();
    virtual void f();
    int pad;
};
class PropDestroyTrack : public Track_181700 {
  public:
    PropDestroyTrack();
    virtual void f();
    int a;
    int b;
    int c;
};
PropDestroyTrack::PropDestroyTrack() : Track_181700(), b(0), c(0) {
    a = 1;
}