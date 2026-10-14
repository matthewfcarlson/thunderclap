// Same code shape as 0x0012fc90 (propagated; names are from that function)
extern "C" {
void __cdecl thunk_FUN_00267090(void*);
void __cdecl thunk_FUN_00267090b(void*);
void __cdecl thunk_FUN_00267090c(void*);
extern char g_vftable_target;
}

struct BaseCls_238ca0 {
  public:
    void Dtor();
};

class DebugPrintCondition {
  public:
    virtual ~DebugPrintCondition();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned char flag);
    virtual void v6();
    char pad[8];
    void* m_p1;
    void* m_p2;
};

void* DebugPrintCondition::v5(unsigned char flag) {
    *(char**)this = &g_vftable_target;
    thunk_FUN_00267090(m_p1);
    thunk_FUN_00267090b(m_p2);
    ((BaseCls_238ca0*)this)->Dtor();
    if (flag & 1) {
        thunk_FUN_00267090c(this);
    }
    return this;
}
