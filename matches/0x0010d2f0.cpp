class Base {
  public:
    Base();
    virtual void Fn();
    char pad[4];
    int c;
};
class Part {
  public:
    Part();
    char pad[4];
};
class KeywordWaitTrack : public Base {
  public:
    KeywordWaitTrack();
    virtual void Fn();
    int a;
    float b;
    char gap[4];
    Part part;
    char pad2[4];
    char flag;
};
KeywordWaitTrack::KeywordWaitTrack() : Base(), a(0), b(-1.0f), part() {
    flag = 0;
    c = 1;
}