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
    virtual void v15();
    virtual int v16(const char*);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    void MakePath(const char*, char*, unsigned int);
    int MapError(unsigned long);
    char pad[0xb0];
    int lastError;
};
extern "C" int __stdcall CheckFn(const char*);
extern "C" unsigned long __stdcall GetLastError();
int XboxDrive::v16(const char* path) {
    char buf[0x101];
    MakePath(path, buf, 0x101);
    if (CheckFn(buf)) {
        lastError = 0;
        return 1;
    }
    lastError = MapError(GetLastError());
    return 0;
}