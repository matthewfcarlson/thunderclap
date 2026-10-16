class Base {
  public:
    Base();
    virtual void f();
};
class LuaTrack : public Base {
  public:
    LuaTrack();
    char pad[8];
    int a;
    float b;
    int c;
    int d;
};
LuaTrack::LuaTrack() : Base(), a(0), b(-1.0f), c(0), d(0) {}