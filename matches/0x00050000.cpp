class ParamValueEnum_50000 {
  public:
    ParamValueEnum_50000(int);
    virtual void f();
    char pad[12];
};
class ParamEnumConstList_50000 : public ParamValueEnum_50000 {
  public:
    ParamEnumConstList_50000(int, int, int, int);
    virtual void f();
    int a, b, c;
};
ParamEnumConstList_50000::ParamEnumConstList_50000(int x, int y, int z, int w) : ParamValueEnum_50000(x), a(y), b(z), c(w) {}