// Same code shape as 0x0023aee0 (propagated; names are from that function)
class ScriptReader {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual int vfunc_11(int, int, int);
    int helper1(int, int, int);
    int helper2(int, int);
};
int ScriptReader::vfunc_11(int a, int b, int c) {
    int x = helper1(a, b, 3);
    return helper2(x, c);
}