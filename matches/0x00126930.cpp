class ParamValueEnum_126930 {
  public:
    virtual void f();
    char pad[12];
    ParamValueEnum_126930(int);
};
class ParamEnumConstList_126930 : public ParamValueEnum_126930 {
  public:
    virtual void f();
    int a, b, c;
    ParamEnumConstList_126930(int, int, int, int);
};
ParamEnumConstList_126930::ParamEnumConstList_126930(int x, int y, int z, int w) : ParamValueEnum_126930(x) {
    a = y;
    b = z;
    c = w;
}