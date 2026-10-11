extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern const int g_vt_statement;
extern const int g_vt_string;
extern const int g_vt_scripttoken;

struct CTokenStatement {
    void* vptr;
    char pad[0xc];
    void* m0x10;
    void* vfunc_0(unsigned int flags);
};

void* CTokenStatement::vfunc_0(unsigned int flags) {
    this->vptr = (void*)&g_vt_statement;
    if (this->m0x10) {
        thunk_FUN_00267090(this->m0x10);
        this->m0x10 = 0;
    }
    this->vptr = (void*)&g_vt_string;
    if (this->m0x10) {
        thunk_FUN_00267090(this->m0x10);
        this->m0x10 = 0;
    }
    this->vptr = (void*)&g_vt_scripttoken;
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}
