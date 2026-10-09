class ImageSelector {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual char vfunc_10(int x, int y);
};
char ImageSelector::vfunc_10(int x, int y) {
    if (x != 0) {
        if (x == 4)
            return 1;
        return 0;
    }
    return 1;
}
