class Base {
  public:
    Base();
    virtual void f();
    char p[4];
};
class Sub {
  public:
    Sub();
    char data[8];
};
class SemaphoreClearTrack : public Base {
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
SemaphoreClearTrack::SemaphoreClearTrack() : Base(), n(0), v(-1.0f), sub(), x(0), y(0) {
    *(int*)((char*)this + 8) = 1;
}