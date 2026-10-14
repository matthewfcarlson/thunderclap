class Local_232c40 {
  public:
    char data[8];
    void Init();
    void Finish();
};
class Helper_232c40 {
  public:
    void Do(Local_232c40*);
};
class T_232c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool Run(int, int, Local_232c40*);
    char Target(int a, int b, Helper_232c40* h);
};
char T_232c40::Target(int a, int b, Helper_232c40* h) {
    Local_232c40 x;
    x.Init();
    bool r = Run(a, b, &x);
    if (r)
        ((Helper_232c40*)((char*)h + 8))->Do(&x);
    x.Finish();
    return r;
}