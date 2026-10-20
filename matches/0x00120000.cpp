class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class ParamEnumConstList_120000 : public Base {
  public:
    ParamEnumConstList_120000(int, int, int, int);
    int a, b, c;
};
ParamEnumConstList_120000::ParamEnumConstList_120000(int x, int y, int z, int w) : Base(x), a(y), b(z), c(w) {}