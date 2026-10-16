class Base {
  public:
    Base(float);
    virtual void f();
};
class CDriftTrack;
class Param {
  public:
    virtual void f();
};
class ParamFloatConstRange : public Base {
  public:
    ParamFloatConstRange(float, CDriftTrack*);
    virtual void f();
    char pad[12];
    CDriftTrack* track;
};
ParamFloatConstRange::ParamFloatConstRange(float x, CDriftTrack* t) : Base(x), track(t) {}