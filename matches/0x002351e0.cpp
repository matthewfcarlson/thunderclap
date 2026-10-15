namespace fight {
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, int);
    virtual void* v6(int);
    int pad;
    int a;
    int b;
};
} // namespace fight
class Result {
  public:
    char go(int, int, int);
};
char fight::ParamValueBranch::v5(int x, int y, int z) {
    Result* p = (Result*)v6(x);
    if (p) {
        int first = a;
        int last = z;
        int second = b;
        return p->go(first, second, last);
    }
    return 0;
}