extern "C" void _ReadWriteBarrier();
class Root {
  public:
    virtual void fn();
    Root();
    char pad[8];
};
class Track_147590 : public Root {
  public:
    Track_147590() { a = 0; }
    int a;
};
class CivilianThrowTrack : public Track_147590 {
  public:
    virtual void fn();
    CivilianThrowTrack();
    int b, c;
    float d, e, f, g, h, i;
    int j, k, l;
    float m;
};
CivilianThrowTrack::CivilianThrowTrack() {
    b = 0;
    c = 0;
    d = -1.0f;
    _ReadWriteBarrier();
    e = 10.0f;
    f = 100.0f;
    g = 10.0f;
    h = 100.0f;
    i = 3.1415927f / 2;
    j = 0;
    k = 0;
    l = 0;
    m = 1.0f;
}