class ParamValueFloat_6cd10 {
  public:
    ParamValueFloat_6cd10(float);
    virtual void f();
};
class CDriftTrack;
class Param {
  public:
    virtual void f();
};
class ParamFloatConstRange : public ParamValueFloat_6cd10 {
  public:
    ParamFloatConstRange(float, CDriftTrack*);
    virtual void f();
    char pad[12];
    CDriftTrack* track;
};
ParamFloatConstRange::ParamFloatConstRange(float x, CDriftTrack* t) : ParamValueFloat_6cd10(x), track(t) {}