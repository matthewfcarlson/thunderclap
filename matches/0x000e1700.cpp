class FEDoAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool vfunc_4(int a, int b, int c, int d);
    int m4;
    int m8;
    int mc;
    char pad[4];
    char mStr[32];
};

int strncmp(const char*, const char*, unsigned int);

bool FEDoAction::vfunc_4(int a, int b, int c, int d) {
    if (a == m4 && m8 == c && mc == d) {
        if (mStr[0] == 0)
            return true;
        char* p = (char*)(b + 0x1734);
        if (p != 0 && strncmp(p, mStr, 0x20) == 0)
            return true;
    }
    return false;
}
