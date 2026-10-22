class Track_133ce0 {
  public:
    Track_133ce0();
    virtual void f();
};
class HoverTrack : public Track_133ce0 {
  public:
    HoverTrack();
    char pad[4];
    int a;
    int b;
    float c;
    int d;
};
HoverTrack::HoverTrack() {
    b = 0;
    d = 0;
    c = -1.0f;
    a = 1;
}