class Track_170e70 {
  public:
    Track_170e70();
    virtual void f();
    char pad[4];
};
class ChargeClearTrack : public Track_170e70 {
  public:
    ChargeClearTrack();
    int a;
    int zero;
    float b;
    char c;
    virtual void f();
};
ChargeClearTrack::ChargeClearTrack() : Track_170e70() {
    c = 1;
    a = 1;
    zero = 0;
    b = -1.0f;
}