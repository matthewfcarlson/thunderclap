class Track_10d090 {
  public:
    Track_10d090();
    virtual void f();
    char p[4];
};
class Sub {
  public:
    Sub();
    char data[8];
};
class SemaphoreClearTrack : public Track_10d090 {
  public:
    SemaphoreClearTrack();
    virtual void f();
    char a[4];
    int n;
    float v;
    char pad[4];
    Sub sub;
    char x, y;
};
SemaphoreClearTrack::SemaphoreClearTrack() : Track_10d090(), n(0), v(-1.0f), sub(), x(0), y(0) {
    *(int*)((char*)this + 8) = 1;
}