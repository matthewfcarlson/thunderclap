class Base {
  public:
    Base();
    virtual void fn();
    char pad[4];
};
class DebugPrintTrack : public Base {
  public:
    DebugPrintTrack();
    int count;
    int* p;
    float value;
    int a;
    int b;
};
DebugPrintTrack::DebugPrintTrack() : Base(), p(0), value(-1.0f), a(0), b(0) {
    count = 1;
}