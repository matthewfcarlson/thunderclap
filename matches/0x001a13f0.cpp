class Track_1a13f0 {
  public:
    Track_1a13f0();
    virtual void f();
};
class LuaTrack : public Track_1a13f0 {
  public:
    LuaTrack();
    char pad[8];
    int a;
    float b;
    int c;
    int d;
};
LuaTrack::LuaTrack() : Track_1a13f0(), a(0), b(-1.0f), c(0), d(0) {}