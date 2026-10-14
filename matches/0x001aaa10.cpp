extern "C" char DAT_0041c4f0[];
extern void* __cdecl Alloc(unsigned int);
struct Event_StringCondition {
    int x[6];
    void Initialize(int);
};
struct Sub_1aaa10 {
    void Init();
};
struct Factory_1aaa10 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Event_StringCondition* vfunc_5();
};
Event_StringCondition* Factory_1aaa10::vfunc_5() {
    Event_StringCondition* p = (Event_StringCondition*)Alloc(0x18);
    if (p) {
        p->Initialize(0);
        p->x[0] = ((int)DAT_0041c4f0);
        ((Sub_1aaa10*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}