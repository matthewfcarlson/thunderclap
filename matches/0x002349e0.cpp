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
    vf = 0x4279fc;
    sub.Init(s);
    vf = 0x427a78;
}