class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub();
};
class AIHistorySetTrack : public Base {
  public:
    AIHistorySetTrack();
    virtual void f();
    int a;
    float b;
    char c;
    char gap[3];
    Sub sub;
};
AIHistorySetTrack::AIHistorySetTrack() : Base(), a(0), b(-1.0f), c(0), sub() {
    *(int*)((char*)this + 8) = 1;
}