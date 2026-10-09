extern int vftable;
extern void __cdecl thunk(struct CMoveAgent*);

struct Ref { virtual void a(); virtual void b(); };

struct CMoveAgent {
    virtual void x0();
    virtual void x1();
    virtual CMoveAgent* vfunc_2(unsigned char param);
    char pad[0x64];
    Ref* member;
    void cleanupM();
};

CMoveAgent* CMoveAgent::vfunc_2(unsigned char param) {
    *(int*)this = (int)&vftable;
    this->member->b();
    this->member = 0;
    this->cleanupM();
    if (param & 1) thunk(this);
    return this;
}
