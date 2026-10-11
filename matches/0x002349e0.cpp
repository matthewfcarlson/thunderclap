extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a78[];
class Sub {
  public:
    void Init(const char*);
};
class ParamValueString {
  public:
    int vf;
    int pad;
    Sub sub;
    ParamValueString(const char*);
};
ParamValueString::ParamValueString(const char* s) {
    vf = ((int)DAT_004279fc);
    sub.Init(s);
    vf = ((int)DAT_00427a78);
}