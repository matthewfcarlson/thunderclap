extern "C" void __cdecl thunk_FUN_00267090_a(void*);
extern "C" void __cdecl thunk_FUN_00267090_b(void*);
extern "C" void* g_vtStr[];
extern "C" void* g_vtBase[];

class CTokenString {
  public:
    void** mVptr;
    char pad[0xC];
    void* mPtr;
    CTokenString* vfunc_0(unsigned char param);
};

CTokenString* CTokenString::vfunc_0(unsigned char param) {
    this->mVptr = g_vtStr;
    if (this->mPtr != 0) {
        thunk_FUN_00267090_a(this->mPtr);
        this->mPtr = 0;
    }
    this->mVptr = g_vtBase;
    if (param & 1) {
        thunk_FUN_00267090_b((void*)this);
    }
    return this;
}
