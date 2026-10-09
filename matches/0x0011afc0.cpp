struct Init { void init(int); };
extern char g_hgpc_vftable;
struct HasGroundPointCondition { char pad[12]; unsigned char x; unsigned char y; };
void* __cdecl alloc(unsigned int);
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual HasGroundPointCondition* create();
};
HasGroundPointCondition* Factory::create() {
    HasGroundPointCondition* p = (HasGroundPointCondition*)alloc(0x10);
    if (p) {
        ((Init*)p)->init(0);
        *(void**)p = (void*)&g_hgpc_vftable;
        p->x = 1;
        p->y = 0;
        return p;
    }
    return 0;
}
