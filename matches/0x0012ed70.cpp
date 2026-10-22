class Track_12ed70 {
  public:
    Track_12ed70();
    virtual void fn();
    char pad[4];
};
class DebugPrintTrack : public Track_12ed70 {
  public:
    DebugPrintTrack();
    int count;
    int* p;
    float value;
    int a;
    int b;
};
DebugPrintTrack::DebugPrintTrack() : Track_12ed70(), p(0), value(-1.0f), a(0), b(0) {
    count = 1;
}