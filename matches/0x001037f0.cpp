// Same code shape as 0x000ffeb0 (propagated; names are from that function)
struct Thing {
    virtual void a();
    virtual void b();
};
extern int handVtable;
struct Helper {
    void run();
};
void __cdecl thunk_FUN_00267090(void*);
class CHand2HandAgent {
  public:
    virtual void v0();
    virtual void v1();
    virtual CHand2HandAgent* vfunc_2(unsigned char);
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x58];
    Thing* thing;
};
CHand2HandAgent* CHand2HandAgent::vfunc_2(unsigned char param) {
    Thing* t = thing;
    *(int*)this = (int)&handVtable;
    t->b();
    thing = 0;
    ((Helper*)this)->run();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
