extern "C" char DAT_0041d3cc[];
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Sub {
  public:
    void Init();
};
class Event_TriggerVolumeNameCondition : public Condition {
  public:
    void Init(int);
    char pad[0x0c];
    Sub sub;
};
extern void* __cdecl Allocate(int);
class Factory {
  public:
    void* v[6];
    void* vfunc_5();
};
void* Factory::vfunc_5() {
    Event_TriggerVolumeNameCondition* p = (Event_TriggerVolumeNameCondition*)Allocate(0x18);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041d3cc);
        p->sub.Init();
        return p;
    }
    return 0;
}