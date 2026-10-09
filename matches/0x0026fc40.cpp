class XboxDrive {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int vfunc_17(const char*);
    virtual int f18();
    virtual int f19();
    virtual int f20();
    virtual int f21();
    char pad[0xb0];
    int err;
    int helper(const char*, char*, int);
    int seterr(unsigned int);
};
extern int __stdcall FUN_0021257d(char*);
extern unsigned int __stdcall GetLastError();
int XboxDrive::vfunc_17(const char* path) {
    char buf[0x101];
    int r = helper(path, buf, 0x101);
    if (FUN_0021257d(buf)) {
        err = 0;
        return 1;
    }
    err = seterr(GetLastError());
    return 0;
}