extern "C" __stdcall unsigned long GetLastError();
int __stdcall Api(char* path, int flag);

namespace core {
class XboxDrive {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int vfunc_15(const char* p);
    void MakePath(const char* p, char* out, int n);
    int Translate(unsigned long e);
    char pad[0xb4 - 4];
    int mErr;
};

int XboxDrive::vfunc_15(const char* p) {
    char buf[0x101];
    MakePath(p, buf, 0x101);
    if (Api(buf, 0)) {
        mErr = 0;
        return 1;
    }
    mErr = Translate(GetLastError());
    return 0;
}
} // namespace core
