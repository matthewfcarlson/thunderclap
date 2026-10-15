class Result {
  public:
    char Work(int, int, int, int);
};
namespace fight {
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, int);
    virtual Result* v6(int);
    int base;
};
class ParamValueConditionGroup : public ParamValue {
  public:
    int a;
    int b;
    virtual char v5(int, int, int);
};
} // namespace fight
char fight::ParamValueConditionGroup::v5(int x, int y, int z) {
    Result* p = v6(x);
    if (p) {
        int q = z;
        int aa = a;
        int bb = b;
        return p->Work(aa, bb, y, q);
    }
    return 0;
}