class Track_180db0 {
  public:
    Track_180db0();
    virtual void f();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class PropAnimationTrack : public Track_180db0 {
  public:
    PropAnimationTrack();
    virtual void f();
    int a;
    float b;
    int c;
    Part part;
    float e;
    int d;
    float h;
    int g;
};
PropAnimationTrack::PropAnimationTrack()
    : Track_180db0(), a(0), b(-1.0f), c(0), part(), e(1.0f), d(0), h(-1.0f), g(0) {
    *(int*)((char*)this + 8) = 1;
}