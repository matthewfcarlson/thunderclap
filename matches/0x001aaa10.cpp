extern void* __cdecl Alloc(unsigned int);
struct Event_StringCondition {
    int x[6];
    void Initialize(int);
};
struct Sub {
    void Init();
};
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Event_StringCondition* vfunc_5();
};
Event_StringCondition* Factory::vfunc_5() {
    Event_StringCondition* p = (Event_StringCondition*)Alloc(0x18);
    if (p) {
        p->Initialize(0);
        p->x[0] = 0x41c4f0;
        ((Sub*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}