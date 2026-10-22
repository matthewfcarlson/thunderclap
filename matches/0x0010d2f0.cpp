class Track_10d2f0 {
  public:
    Track_10d2f0();
    virtual void Fn();
    char pad[4];
    int c;
};
class Part {
  public:
    Part();
    char pad[4];
};
class KeywordWaitTrack : public Track_10d2f0 {
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
KeywordWaitTrack::KeywordWaitTrack() : Track_10d2f0(), a(0), b(-1.0f), part() {
    flag = 0;
    c = 1;
}