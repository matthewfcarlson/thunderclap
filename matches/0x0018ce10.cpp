class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class TimerSetTrack : public Base {
  public:
    TimerSetTrack();
    virtual void f();
    int a, b, c;
};
TimerSetTrack::TimerSetTrack() : Base() {
    a = 0;
    b = 0;
    c = 0;
    *(int*)((char*)this + 8) = 1;
}