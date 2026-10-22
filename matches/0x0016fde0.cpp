class Track_16fde0 {
  public:
    Track_16fde0();
    virtual void f();
    int m;
};
class ChargeTrack : public Track_16fde0 {
  public:
    ChargeTrack();
    virtual void f();
    int count;
    int a;
    float b;
    int c;
    char d;
    char pad1[3];
    float e;
};
ChargeTrack::ChargeTrack() : Track_16fde0() {
    a = 0;
    c = 0;
    d = 0;
    b = -1.0f;
    e = 1.0f;
    count = 1;
}