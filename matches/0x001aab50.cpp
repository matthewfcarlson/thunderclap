extern "C" char DAT_0041c5b0[];
extern void* __cdecl FUN_0008d690(unsigned int);
struct Event {
    void Init(int);
};
struct Tail {
    void Run();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
    Event* p = (Event*)FUN_0008d690(0x18);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041c5b0);
        ((Tail*)((char*)p + 0x10))->Run();
        return p;
    }
    return 0;
}