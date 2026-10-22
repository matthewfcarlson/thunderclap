class Track_18ce10 {
  public:
    Track_18ce10();
    virtual void f();
    char pad[8];
};
class TimerSetTrack : public Track_18ce10 {
  public:
    TimerSetTrack();
    virtual void f();
    int a, b, c;
};
TimerSetTrack::TimerSetTrack() : Track_18ce10() {
    a = 0;
    b = 0;
    c = 0;
    *(int*)((char*)this + 8) = 1;
}