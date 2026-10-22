class Track_180d20 {
  public:
    Track_180d20();
    virtual void f();
};
class PropDropTrack : public Track_180d20 {
  public:
    PropDropTrack();
    char pad[4];
    int a;
    int b;
    int c;
};
PropDropTrack::PropDropTrack() : Track_180d20() {
    b = 0;
    c = -1;
    a = 1;
}