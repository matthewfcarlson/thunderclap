class Service_274670 {
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
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual int a15(int*);
};
class Helper_274670 {
  public:
    int Run();
};
struct Manager_274670 {
    virtual void Reset();
    virtual void Finish();
};
struct Data_274670 {
    char pad[4];
    Manager_274670 manager;
    char pad2[4];
    Service_274670* service;
    char pad3[8];
    int stored;
};
class core_DriveCreateDirectoryRequest {
  public:
    char pad[8];
    Data_274670* base;
    int vfunc_1();
};
int core_DriveCreateDirectoryRequest::vfunc_1() {
    Service_274670* svc = base->service;
    int value = svc->a15((int*)((char*)this + 12));
    int result = ((Helper_274670*)svc)->Run();
    base->manager.Reset();
    base->stored = result;
    base->manager.Finish();
    return value;
}
