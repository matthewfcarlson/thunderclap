class ScriptReader {
  public:
    int v0(int, int);
    int v1(int, int);
    int v2(int, int);
    int v3(int, int);
    int v4(int, int);
    int v5(int, int);
    int helper1(int, int, int);
    int helper2(int, int, int);
    virtual int vfunc_6(int a, int b, int c, int d, int e);
};
int ScriptReader::vfunc_6(int a, int b, int c, int d, int e) {
    int x = helper1(a, b, 4);
    return helper2(x, d, e);
}