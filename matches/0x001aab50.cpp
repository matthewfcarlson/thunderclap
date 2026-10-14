extern "C" char DAT_0041c5b0[];
extern void* __cdecl FUN_0008d690(unsigned int);
struct Event_1aab50 {
    void Init(int);
};
struct Tail_1aab50 {
    void Run();
};
class Factory_1aab50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* Factory_1aab50::vfunc_5() {
    Event_1aab50* p = (Event_1aab50*)FUN_0008d690(0x18);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041c5b0);
        ((Tail_1aab50*)((char*)p + 0x10))->Run();
        return p;
    }
    return 0;
}