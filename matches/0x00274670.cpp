class Service {
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
class Helper {
  public:
    int Run();
};
struct Manager {
    virtual void Reset();
    virtual void Finish();
};
struct Data {
    char pad[4];
    Manager manager;
    char pad2[4];
    Service* service;
    char pad3[8];
    int stored;
};
class core_DriveCreateDirectoryRequest {
  public:
    char pad[8];
    Data* base;
    int vfunc_1();
};
int core_DriveCreateDirectoryRequest::vfunc_1() {
    Service* svc = base->service;
    int value = svc->a15((int*)((char*)this + 12));
    int result = ((Helper*)svc)->Run();
    base->manager.Reset();
    base->stored = result;
    base->manager.Finish();
    return value;
}
